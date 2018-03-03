/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 04:26:10 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 07:23:03 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static int			build_nodes(t_network *network, t_data const *const data)
{
	int				nodecount;
	t_rlist			*rooms;

	nodecount = -1;
	rooms = data->rooms;
	while (rooms && nodecount++ > (int)0x80000000)
		rooms = rooms->next;
	network->nodes = (t_node **)ft_memalloc(sizeof(t_node *) * (nodecount + 1));
	network->nodes_count = nodecount;
	rooms = data->rooms;
	while (nodecount--)
	{
		network->nodes[nodecount] = (t_node *)ft_memalloc(sizeof(t_node));
		network->nodes[nodecount]->name = ft_strdup(rooms->room->name);
		network->nodes[nodecount]->pos = rooms->room->pos;
		if (ft_strequ(rooms->room->name, data->start->name))
			network->entry = network->nodes[nodecount];
		else if (ft_strequ(rooms->room->name, data->end->name))
			network->exit = network->nodes[nodecount];
		verbose("	Built node Name(%s).\n", network->nodes[nodecount]->name);
		rooms = rooms->next;
	}
	return (0);
}

static int			count_connections(char *name, t_tlist *tubes)
{
	int				count;

	count = 0;
	while (tubes)
	{
		if (ft_strequ(name, tubes->tube->room1->name) ||
			ft_strequ(name, tubes->tube->room2->name))
		{
			count++;
		}
		tubes = tubes->next;
	}
	return (count);
}

static int			fill_connections(t_node *node, t_node **list_nodes,
						t_tlist *tlist)
{
	int				i;
	t_node			**nodes_temp;

	i = 0;
	while (tlist)
	{
		if (ft_strequ(node->name, tlist->tube->room1->name) ||
			ft_strequ(node->name, tlist->tube->room2->name))
		{
			nodes_temp = list_nodes;
			while (*nodes_temp)
			{
				if (!ft_strequ((*nodes_temp)->name, node->name) &&
					(ft_strequ((*nodes_temp)->name, tlist->tube->room1->name) ||
					ft_strequ((*nodes_temp)->name, tlist->tube->room2->name)))
				{
					node->nodes[i++] = (*nodes_temp);
				}
				nodes_temp++;
			}
		}
		tlist = tlist->next;
	}
	return (0);
}

static int			link_nodes(t_network *network, t_data const *const data)
{
	t_node			**nodes;
	t_tlist			*tlist;
	int				i;

	nodes = network->nodes;
	while (*nodes)
	{
		tlist = data->tubes;
		(*nodes)->connections = count_connections((*nodes)->name, tlist);
		(*nodes)->nodes = (t_node **)ft_memalloc(
			sizeof(t_node *) * ((*nodes)->connections + 1));
		(*nodes)->distances = (int *)ft_memalloc(
			sizeof(int) * ((*nodes)->connections + 1));
		fill_connections(*nodes, network->nodes, tlist);
		i = -1;
		while (++i < (*nodes)->connections)
			(*nodes)->distances[i] = 1;
		verbose("	Linked node Name(%s) to %d nodes.\n",
			(*nodes)->name, (*nodes)->connections);
		nodes++;
	}
	return (0);
}

t_network			*build_network(t_data *data)
{
	t_network		*network;
	t_node			**nodes_tmp;
	int				nodes;
	int				connection;

	network = (t_network *)ft_memalloc(sizeof(t_network));
	network->units = data->ants;
	build_nodes(network, data);
	link_nodes(network, data);
	nodes_tmp = network->nodes - 1;
	while (*(++nodes_tmp))
		if (!(*nodes_tmp)->nodes)
			error(ERR_ISOLATED_ROOM, ERR_WARNING);
	nodes = -1;
	while (network->nodes[++nodes])
	{
		verbose("Node detected: Name(%s), Connections(%d)\n",
			network->nodes[nodes]->name, network->nodes[nodes]->connections);
		connection = -1;
		while (network->nodes[nodes]->nodes[++connection])
			verbose("    Connects with: Name(%s)\n",
				network->nodes[nodes]->nodes[connection]->name);
	}
	return (network);
}
