/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ellipsis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 01:53:16 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 02:16:10 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		args;
	int			ret;

	va_start(args, str);
	ret = ft_printf_valist(str, &args);
	va_end(args);
	return (ret);
}

int				ft_printf_buf(char *buffer, const char *str, ...)
{
	va_list		args;
	int			ret;

	va_start(args, str);
	ret = ft_printf_buf_valist(buffer, str, &args);
	va_end(args);
	return (ret);
}
