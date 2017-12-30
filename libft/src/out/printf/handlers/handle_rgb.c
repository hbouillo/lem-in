/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:27:52 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:54:58 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		color_reset(char **buf)
{
	static char const *const	escape_seq = FT_PRINTF_RGB_RESET;
	char const *ptr;

	ptr = escape_seq;
	while (*ptr)
		*((*buf)++) = *(ptr++);
	return (0);
}

int				handle_rgb(va_list *arg, t_convseq *convseq, char **buf)
{
	static char const *const	escape_seq = FT_PRINTF_RGB_ESC;
	char const *ptr;
	t_argb		argb;
	char		*tmp;

	if (convseq->flags & FT_PRINTF_FLAG_ZERO)
		return (color_reset(buf));
	ptr = escape_seq;
	argb = va_arg(*arg, t_argb);
	while (*ptr)
		*((*buf)++) = *(ptr++);
	tmp = ft_uctoabase(argb.argb[1], BASE_DEC);
	while(*tmp)
		*((*buf)++) = *(tmp++);
	*((*buf)++) = ';';
	tmp = ft_uctoabase(argb.argb[2], BASE_DEC);
	while(*tmp)
		*((*buf)++) = *(tmp++);
	*((*buf)++) = ';';
	tmp = ft_uctoabase(argb.argb[3], BASE_DEC);
	while(*tmp)
		*((*buf)++) = *(tmp++);
	*((*buf)++) = 'm';
	return (0);
}
