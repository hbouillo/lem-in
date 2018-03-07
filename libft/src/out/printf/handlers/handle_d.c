/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:27:52 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:55:21 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		adjust_convseq(char *str, t_convseq *convseq)
{
	if (convseq->prec < 0)
		convseq->prec = 1;
	else if (convseq->prec >= 0)
		convseq->flags &= ~FT_PRINTF_FLAG_ZERO;
	convseq->prec = ft_nbrmax(convseq->prec + (*str == '-' ? 1 : 0),
		ft_strlen(str));
	convseq->wid -= convseq->prec + ((convseq->flags & FT_PRINTF_FLAG_PLUS ||
		convseq->flags & FT_PRINTF_FLAG_SPACE) && *str != '-' ? 1 : 0);
	convseq->prec -= ft_strlen(str);
}

static void		write_flags(char **str, t_convseq *convseq, char **buf)
{
	while (!(convseq->flags & FT_PRINTF_FLAG_MINUS) &&
		!(convseq->flags & FT_PRINTF_FLAG_ZERO) && convseq->wid-- > 0)
		*((*buf)++) = ' ';
	if ((convseq->flags & FT_PRINTF_FLAG_PLUS) && **str != '-')
		*((*buf)++) = '+';
	else if ((convseq->flags & FT_PRINTF_FLAG_SPACE) && **str != '-')
		*((*buf)++) = ' ';
	else if (**str == '-')
		*((*buf)++) = *((*str)++);
	while (convseq->prec-- > 0)
		*((*buf)++) = '0';
	while (!(convseq->flags & FT_PRINTF_FLAG_MINUS) &&
		(convseq->flags & FT_PRINTF_FLAG_ZERO) && convseq->wid-- > 0)
		*((*buf)++) = '0';
}

int				handle_d(va_list *arg, t_convseq *convseq, char **buf)
{
	char		buffer[65];
	char		*str;

	str = buffer;
	argtoabase(arg, convseq->len, BASE_DEC, str);
	while (*str == '0')
		str++;
	adjust_convseq(str, convseq);
	write_flags(&str, convseq, buf);
	while (*str)
	{
		**buf = *str;
		(*buf)++;
		str++;
	}
	while ((convseq->flags & FT_PRINTF_FLAG_MINUS) && convseq->wid-- > 0)
		*((*buf)++) = ' ';
	return (0);
}
