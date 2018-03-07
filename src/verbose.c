/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 02:16:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/07 05:12:49 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				verbose(char *str, ...)
{
	va_list		args;
	int			ret;

	if (!get_arg(ARG_VERBOSE))
		return (0);
	va_start(args, str);
	ft_printf("%rgb", 0x777777);
	ret = ft_printf_valist(str, &args);
	ft_printf("%0rgb");
	va_end(args);
	return (ret);
}

int				sverbose(char *str, ...)
{
	va_list		args;
	int			ret;

	if (!get_arg(ARG_PRINT) && !get_arg(ARG_VERBOSE))
		return (0);
	va_start(args, str);
	ft_printf("%rgb", 0x777777);
	ret = ft_printf_valist(str, &args);
	ft_printf("%0rgb");
	va_end(args);
	return (ret);
}

void			verbose_path(t_path path)
{
	int			i;

	verbose("Path is [ ");
	i = -1;
	while (++i < path.length)
	{
		verbose("%s", path.nodes[i]);
		if (i < path.length - 1)
			verbose(" - ");
	}
	verbose(" ]\n");
}

void			sverbose_path(t_path path)
{
	int			i;

	sverbose("Path is [ ");
	i = -1;
	while (++i < path.length)
	{
		sverbose("%s", path.nodes[i]);
		if (i < path.length - 1)
			sverbose(" - ");
	}
	sverbose(" ]\n");
}
