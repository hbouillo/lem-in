/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_m_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:27:52 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:55:12 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t		wstrlen(wchar_t *wstr, t_prec precision)
{
	size_t			len;
	int				tmplen;

	len = 0;
	while (*wstr)
	{
		tmplen = utf8_len(*wstr);
		len += tmplen;
		precision -= tmplen;
		if (precision < 0)
			len -= tmplen;
		wstr++;
	}
	return (len);
}

static void			adjust_convseq(wchar_t *wstr, t_convseq *convseq)
{
	if (convseq->prec < 0)
		convseq->prec = wstrlen(wstr, FT_PRINTF_PREC_MAX);
	convseq->prec = ft_nbrmin(wstrlen(wstr, convseq->prec), convseq->prec);
	convseq->wid -= convseq->prec;
}

int					handle_m_s(va_list *arg, t_convseq *convseq, char **buf)
{
	static wchar_t	wnull[7] = { '(', 'n', 'u', 'l', 'l', ')', 0};
	wchar_t			*wstr;
	int				tmplen;

	wstr = (wchar_t *)va_arg(*arg, wchar_t *);
	if (!wstr)
		wstr = wnull;
	adjust_convseq(wstr, convseq);
	while (!(convseq->flags & FT_PRINTF_FLAG_MINUS) && convseq->wid-- > 0)
		*((*buf)++) = convseq->flags & FT_PRINTF_FLAG_ZERO ? '0' : ' ';
	while (*wstr && convseq->prec > 0)
	{
		tmplen = write_utf8_seq(*wstr, buf);
		convseq->prec -= tmplen;
		wstr++;
	}
	while ((convseq->flags & FT_PRINTF_FLAG_MINUS) && convseq->wid-- > 0)
		*((*buf)++) = ' ';
	return (0);
}
