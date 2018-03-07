/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:27:52 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:54:55 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			adjust_convseq(char *str, t_convseq *convseq)
{
	if (convseq->prec < 0)
		convseq->prec = 1;
	else if (convseq->prec >= 0)
		convseq->flags &= ~FT_PRINTF_FLAG_ZERO;
	convseq->prec = ft_nbrmax(convseq->prec, ft_strlen(str));
	convseq->wid -= convseq->prec;
	convseq->prec -= ft_strlen(str);
}

int					handle_u(va_list *arg, t_convseq *convseq, char **buf)
{
	char			buffer[65];
	char			*str;

	str = buffer;
	uargtoabase(arg, convseq->len, BASE_DEC, str);
	while (*str == '0')
		str++;
	adjust_convseq(str, convseq);
	while (!(convseq->flags & FT_PRINTF_FLAG_MINUS) && convseq->wid-- > 0)
		*((*buf)++) = convseq->flags & FT_PRINTF_FLAG_ZERO ? '0' : ' ';
	while (convseq->prec-- > 0)
		*((*buf)++) = '0';
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
