/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:28:14 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 02:14:05 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static void		parse_format(t_convseq *convseq, const char **str)
{
	while (convseq->conv == no_conv)
	{
		if (convseq->status < flags && (set_flags(str, convseq)))
			convseq->status = flags;
		else if (convseq->status < width
				&& (set_width(str, convseq)))
			convseq->status = width;
		else if (convseq->status < precision
				&& (set_precision(str, convseq)))
			convseq->status = precision;
		else if (convseq->status < length
				&& (set_length(str, convseq)))
			convseq->status = length;
		else if (convseq->status < conversion
				&& (set_conversion(str, convseq)))
			convseq->status = conversion;
		else
			break ;
	}
}

static void		init_convseq(t_convseq *convseq)
{
	convseq->flags = 0;
	convseq->wid = 0;
	convseq->prec = -1;
	convseq->len = 0;
	convseq->conv = 0;
	convseq->status = 0;
}

static int		handle_arg(va_list *arg, const char **str, char **buf)
{
	t_convseq	convseq;

	init_convseq(&convseq);
	parse_format(&convseq, str);
	if (convseq.conv == no_conv)
		return (-1);
	apply_conv(arg, &convseq, buf);
	return (0);
}

int				ft_printf_valist(const char *str, va_list *args)
{
	char		buffer[FT_PRINTF_BUFF_SIZE];
	char		*bufptr;

	bufptr = buffer;
	while (*str)
	{
		if (*str == FT_PRINTF_SEQ_INIT)
		{
			str++;
			handle_arg(args, &str, &bufptr);
		}
		else
			*(bufptr++) = *(str++);
	}
	write(1, buffer, (int)(bufptr - buffer));
	return ((int)(bufptr - buffer));
}

int				ft_printf_buf_valist(char *buffer, const char *str,
					va_list *args)
{
	char		*bufptr;

	bufptr = buffer;
	while (*str)
	{
		if (*str == FT_PRINTF_SEQ_INIT)
		{
			str++;
			handle_arg(args, &str, &bufptr);
		}
		else
			*(bufptr++) = *(str++);
	}
	return ((int)(bufptr - buffer));
}
