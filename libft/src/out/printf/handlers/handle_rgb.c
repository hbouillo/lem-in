/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:27:52 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 07:12:49 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int						color_reset(char **buf)
{
	static char const *const	escape_seq = FT_PRINTF_RGB_RESET;
	char const					*ptr;

	ptr = escape_seq;
	while (*ptr)
		*((*buf)++) = *(ptr++);
	return (0);
}

static void						put_color_component(char **buf, unsigned char c)
{
	char						tmp[4];
	char						*tmp_ptr;

	tmp_ptr = tmp;
	ft_uctoabase_buf(c, BASE_DEC, tmp);
	while (*tmp_ptr)
		*((*buf)++) = *(tmp_ptr++);
}

int								handle_rgb(va_list *arg, t_convseq *convseq,
									char **buf)
{
	static char const *const	escape_seq = FT_PRINTF_RGB_ESC;
	char const					*ptr;
	int							argb;

	if (convseq->flags & FT_PRINTF_FLAG_ZERO)
		return (color_reset(buf));
	ptr = escape_seq;
	argb = va_arg(*arg, int);
	while (*ptr)
		*((*buf)++) = *(ptr++);
	put_color_component(buf, (unsigned char)((argb & 0xff0000) >> 16));
	*((*buf)++) = ';';
	put_color_component(buf, (unsigned char)((argb & 0xff00) >> 8));
	*((*buf)++) = ';';
	put_color_component(buf, (unsigned char)(argb & 0xff));
	*((*buf)++) = 'm';
	return (0);
}
