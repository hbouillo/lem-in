/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:24:35 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/03 05:06:39 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			error(int exitcode)
{
	ft_printf("ERROR %d\n", exitcode);
	exit(1);
}

int				main(int argc, char **argv)
{
	t_data		*data;
	t_network	*network;

	data = parse_data();
	if (!data->start)
		error(ERR_NO_START_NODE);
	else if (!data->end)
		error(ERR_NO_END_NODE);
	network = build_network(data);
	return (0);
}
