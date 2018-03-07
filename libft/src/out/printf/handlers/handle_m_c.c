/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_m_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:27:52 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:55:18 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				handle_m_c(va_list *arg, t_convseq *convseq, char **buf)
{
	wint_t		c;

	c = (wint_t)va_arg(*arg, wint_t);
	convseq->wid--;
	while (!(convseq->flags & FT_PRINTF_FLAG_MINUS) && convseq->wid-- > 0)
		*((*buf)++) = convseq->flags & FT_PRINTF_FLAG_ZERO ? '0' : ' ';
	write_utf8_seq((wchar_t)c, buf);
	while ((convseq->flags & FT_PRINTF_FLAG_MINUS) && convseq->wid-- > 0)
		*((*buf)++) = ' ';
	return (0);
}
