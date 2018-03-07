/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:27:52 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:55:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				handle_c(va_list *arg, t_convseq *convseq, char **buf)
{
	char		c;

	if (convseq->len == l)
		return (handle_m_c(arg, convseq, buf));
	c = (char)va_arg(*arg, int);
	convseq->wid--;
	while (!(convseq->flags & FT_PRINTF_FLAG_MINUS) && convseq->wid-- > 0)
		*((*buf)++) = convseq->flags & FT_PRINTF_FLAG_ZERO ? '0' : ' ';
	**buf = c;
	(*buf)++;
	while ((convseq->flags & FT_PRINTF_FLAG_MINUS) && convseq->wid-- > 0)
		*((*buf)++) = ' ';
	return (0);
}
