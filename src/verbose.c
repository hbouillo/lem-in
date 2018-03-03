/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 02:16:39 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 06:51:12 by hbouillo         ###   ########.fr       */
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

void			verbose_path(t_path path)
{
	t_llist		*nodes;

	verbose("Path is [ ");
	nodes = path.nodes;
	while (nodes)
	{
		verbose("%s", (char *)nodes->data);
		nodes = nodes->next;
		if (nodes)
			verbose(" - ");
	}
	verbose(" ]\n");
}
