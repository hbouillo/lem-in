/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convseq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:44:31 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:53:37 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./ft_printf.h"

int					set_flags(const char **str, t_convseq *convseq)
{
	int				flags_cmb;

	flags_cmb = 0;
	while (**str && ft_strchr(FT_PRINTF_FLAGS_STR, **str))
	{
		if (**str == '#')
			flags_cmb |= FT_PRINTF_FLAG_SHARP;
		if (**str == '0')
			flags_cmb |= FT_PRINTF_FLAG_ZERO;
		if (**str == '-')
			flags_cmb |= FT_PRINTF_FLAG_MINUS;
		if (**str == '+')
			flags_cmb |= FT_PRINTF_FLAG_PLUS;
		if (**str == ' ')
			flags_cmb |= FT_PRINTF_FLAG_SPACE;
		(*str)++;
	}
	convseq->flags = flags_cmb;
	return (flags_cmb ? 1 : 0);
}

int					set_width(const char **str, t_convseq *convseq)
{
	convseq->wid = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	if (!convseq->wid)
		return (0);
	return (1);
}

int					set_precision(const char **str, t_convseq *convseq)
{
	if (**str != '.')
		return (0);
	(*str)++;
	convseq->prec = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	return (1);
}

int					set_length(const char **str, t_convseq *convseq)
{
	static char const *const	ref = FT_PRINTF_LEN_STR;
	char const					*ref_ptr;
	int							i;

	ref_ptr = ref;
	i = 0;
	while (*ref_ptr)
	{
		i++;
		if (ft_strnequ(*str, ref_ptr + 1, (size_t)*ref_ptr))
		{
			convseq->len = i;
			*str += *ref_ptr;
			return (1);
		}
		ref_ptr += *ref_ptr + 1;
	}
	return (0);
}

int					set_conversion(const char **str, t_convseq *convseq)
{
	static char const *const	ref = FT_PRINTF_CONV_STR;
	char const					*ref_ptr;
	int							i;

	ref_ptr = ref;
	i = 0;
	while (*ref_ptr)
	{
		i++;
		if (ft_strnequ(*str, ref_ptr + 1, (size_t)*ref_ptr))
		{
			convseq->conv = i;
			*str += *ref_ptr;
			return (1);
		}
		ref_ptr += *ref_ptr + 1;
	}
	return (0);
}
