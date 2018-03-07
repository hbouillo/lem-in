/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:27:52 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:54:54 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		adjust_convseq(char *str, t_convseq *convseq)
{
	if (convseq->prec < 0)
		convseq->prec = ft_strlen(str);
	convseq->prec = ft_nbrmin(ft_strlen(str), convseq->prec);
	convseq->wid -= convseq->prec;
}

int				handle_s(va_list *arg, t_convseq *convseq, char **buf)
{
	char		*str;

	if (convseq->len == l)
		return (handle_m_s(arg, convseq, buf));
	str = (char *)va_arg(*arg, char *);
	if (!str)
		str = "(null)";
	adjust_convseq(str, convseq);
	while (!(convseq->flags & FT_PRINTF_FLAG_MINUS) && convseq->wid-- > 0)
		*((*buf)++) = convseq->flags & FT_PRINTF_FLAG_ZERO ? '0' : ' ';
	while (*str && convseq->prec-- > 0)
	{
		**buf = *str;
		(*buf)++;
		str++;
	}
	while ((convseq->flags & FT_PRINTF_FLAG_MINUS) && convseq->wid-- > 0)
		*((*buf)++) = ' ';
	return (0);
}
