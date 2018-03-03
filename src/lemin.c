/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:24:35 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 03:15:12 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int					error(int errcode, char const *const errmsg, char *errtype,
						int errexit)
{
	if (get_arg(ARG_VERBOSE))
	{
		ft_printf("%rgb%s (ERRCODE=%d, ERRMSG=\"%s\")%0rgb\n",
			errexit ? 0xff3835 : 0xf7ba2c, errtype, errcode, errmsg);
		if (errexit)
			exit(1);
	}
	else if (errexit)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	return (1);
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
		error(ERR_NO_START_NODE, ERR_CRITICAL);
	else if (!data->end)
		error(ERR_NO_END_NODE, ERR_CRITICAL);
	network = build_network(data);
	verbose("%d nodes detected in network. Node %s is entry. Node %s \
is exit.\n", network->nodes_count, network->entry->name, network->exit->name);
	solve(network);
	free_data(data);
	free_network(network);
}

int				main(int argc, char **argv)
{
	register_arg_ref("verbose", 'v', 0, ARG_VERBOSE);
	if (parse_args(argc, argv))
	{
		ft_putstr("Usage: lem-in [-v]\n");
		return (1);
	}
	lemin();
	destroy_args();
	//while(1);
	return (0);
}
