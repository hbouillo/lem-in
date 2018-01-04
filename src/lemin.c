/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:24:35 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/04 03:45:48 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			error(int errcode, char const *const errmsg)
{
	ft_printf("Error (ERRCODE=%d, ERRMSG=\"%s\")\n", errcode, errmsg);
	exit(1);
}

static void		free_data(t_data *data)
{
	free_rlist(data->rooms);
	free_tlist(data->tubes);
	free(data);
}

static void		free_network(t_network *network)
{
	t_node		**nodes_temp;

	nodes_temp = network->nodes;
	while (*nodes_temp)
	{
		free((*nodes_temp)->distances);
		free((*nodes_temp)->name);
		free((*nodes_temp)->nodes);
		free(*nodes_temp);
		nodes_temp++;
	}
	free(network->nodes);
	free(network);
}

void			lemin(void)
{
	t_data		*data;
	t_network	*network;

	data = parse_data();
	if (!data->start)
		error(ERR_NO_START_NODE);
	else if (!data->end)
		error(ERR_NO_END_NODE);
	network = build_network(data);
	free_data(data);
	free_network(network);
}

int				main(void)
{
	lemin();
	//while(1);
	return (0);
}
