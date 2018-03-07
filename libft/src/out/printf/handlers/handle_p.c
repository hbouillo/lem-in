/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:27:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:57:43 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void				adjust_convseq(char *str, t_convseq *convseq)
{
	if (convseq->prec < 0)
		convseq->prec = 1;
	convseq->prec = ft_nbrmax(convseq->prec, ft_strlen(str));
	convseq->wid -= convseq->prec;
	convseq->prec -= ft_strlen(str);
	convseq->wid -= 2;
}

static void				write_flags(t_convseq *convseq, char **buf)
{
	while (!(convseq->flags & FT_PRINTF_FLAG_MINUS) &&
		!(convseq->flags & FT_PRINTF_FLAG_ZERO) && convseq->wid-- > 0)
		*((*buf)++) = ' ';
	*((*buf)++) = '0';
	*((*buf)++) = 'x';
	while (!(convseq->flags & FT_PRINTF_FLAG_MINUS) &&
		(convseq->flags & FT_PRINTF_FLAG_ZERO) && convseq->wid-- > 0)
		*((*buf)++) = '0';
	while (convseq->prec-- > 0)
		*((*buf)++) = '0';
}

int						handle_p(va_list *arg, t_convseq *convseq, char **buf)
{
	unsigned long		ptr;
	char				buffer[65];
	char				*str;

	str = buffer;
	ptr = (unsigned long)va_arg(*arg, unsigned long);
	ft_ultoabase_buf(ptr, BASE_HEX, str);
	while (*str == '0')
		str++;
	adjust_convseq(str, convseq);
	write_flags(convseq, buf);
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
