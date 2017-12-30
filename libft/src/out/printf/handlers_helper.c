/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:24:13 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:53:28 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void			argtoabase(va_list *arg, t_len len, char *base, char *buf)
{
	if (len == no_len)
		ft_itoabase_buf(va_arg(*arg, int), base, buf);
	else if (len == hh)
		ft_ctoabase_buf(va_arg(*arg, int), base, buf);
	else if (len == h)
		ft_stoabase_buf(va_arg(*arg, int), base, buf);
	else if (len == ll)
		ft_lltoabase_buf(va_arg(*arg, long long), base, buf);
	else if (len == l)
		ft_ltoabase_buf(va_arg(*arg, long), base, buf);
	else if (len == j)
		ft_imtoabase_buf(va_arg(*arg, intmax_t), base, buf);
	else if (len == z)
		ft_ssitoabase_buf(va_arg(*arg, ssize_t), base, buf);
}

void			uargtoabase(va_list *arg, t_len len, char *base, char *buf)
{
	if (len == no_len)
		ft_uitoabase_buf(va_arg(*arg, unsigned int), base, buf);
	else if (len == hh)
		ft_uctoabase_buf(va_arg(*arg, unsigned int), base, buf);
	else if (len == h)
		ft_ustoabase_buf(va_arg(*arg, unsigned int), base, buf);
	else if (len == ll)
		ft_ulltoabase_buf(va_arg(*arg, unsigned long long), base, buf);
	else if (len == l)
		ft_ultoabase_buf(va_arg(*arg, unsigned long), base, buf);
	else if (len == j)
		ft_uimtoabase_buf(va_arg(*arg, uintmax_t), base, buf);
	else if (len == z)
		ft_sitoabase_buf(va_arg(*arg, size_t), base, buf);
}

int				utf8_len(wchar_t uni)
{
	if (uni <= FT_PRINTF_UTF8_1B)
		return (1);
	else if (uni <= FT_PRINTF_UTF8_2B)
		return (2);
	else if (uni <= FT_PRINTF_UTF8_3B)
		return (3);
	else if (uni <= FT_PRINTF_UTF8_4B)
		return (4);
	return (0);
}

int				write_utf8_seq(wchar_t uni, char **buf)
{
	char		*bufcpy;

	bufcpy = *buf;
	if (uni <= FT_PRINTF_UTF8_1B)
		*((*buf)++) = (char)uni;
	else if (uni <= FT_PRINTF_UTF8_2B)
	{
		*((*buf)++) = (((char)(uni >> 6)) & 0x3F) | FT_PRINTF_UTF8_WFIRST_2B;
		*((*buf)++) = (((char)(uni)) & 0x3f) | FT_PRINTF_UTF8_WNEXT;
	}
	else if (uni <= FT_PRINTF_UTF8_3B)
	{
		*((*buf)++) = (((char)(uni >> 12)) & 0x3F) | FT_PRINTF_UTF8_WFIRST_3B;
		*((*buf)++) = (((char)(uni >> 6)) & 0x3F) | FT_PRINTF_UTF8_WNEXT;
		*((*buf)++) = (((char)(uni)) & 0x3F) | FT_PRINTF_UTF8_WNEXT;
	}
	else if (uni <= FT_PRINTF_UTF8_4B)
	{
		*((*buf)++) = (((char)(uni >> 18)) & 0x3F) | FT_PRINTF_UTF8_WFIRST_4B;
		*((*buf)++) = (((char)(uni >> 12)) & 0x3F) | FT_PRINTF_UTF8_WNEXT;
		*((*buf)++) = (((char)(uni >> 6)) & 0x3F) | FT_PRINTF_UTF8_WNEXT;
		*((*buf)++) = (((char)(uni)) & 0x3F) | FT_PRINTF_UTF8_WNEXT;
	}
	return ((int)(*buf - bufcpy));
}
