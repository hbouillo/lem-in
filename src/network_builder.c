/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 04:26:10 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/04 05:14:48 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

//TODO: ERRORS LIKE TUBE 0-0 OR TWICE SAME TUBE (1-0 and 0-1 is same tube)

static int			build_nodes(t_network *network, t_data const *const data)
{
	int				nodescount;
	t_rlist			*rooms;

	nodescount = 0;
	rooms = data->rooms;
	while (rooms)
	{
		nodescount++;
		rooms = rooms->next;
	}
	network->nodes = (t_node **)ft_memalloc(sizeof(t_node *) * (nodescount + 1));
	network->nodes_count = nodescount;
	rooms = data->rooms;
	while (nodescount--)
	{
		network->nodes[nodescount] = (t_node *)ft_memalloc(sizeof(t_node));
		network->nodes[nodescount]->name = ft_strdup(rooms->room->name);
		network->nodes[nodescount]->pos = rooms->room->pos;
		if (ft_strequ(rooms->room->name, data->start->name))
			network->entry = network->nodes[nodescount];
		else if (ft_strequ(rooms->room->name, data->end->name))
			network->exit = network->nodes[nodescount];
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

static int			fill_connections(t_node *node, t_node **list_nodes, t_tlist *tlist)
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
		(*nodes)->nodes = (t_node **)ft_memalloc(sizeof(t_node *) * ((*nodes)->connections + 1));
		(*nodes)->distances = (int *)ft_memalloc(sizeof(int) * ((*nodes)->connections + 1));
		fill_connections(*nodes, network->nodes, tlist);
		i = -1;
		while (++i < (*nodes)->connections)
			(*nodes)->distances[i] = 1;
		nodes++;
	}
	return (0);
}

t_network			*build_network(t_data *data)
{
	t_network		*network;
	t_node			**nodes_tmp;

	network = (t_network *)ft_memalloc(sizeof(t_network));
	network->units = data->ants;
	build_nodes(network, data);
	link_nodes(network, data);
	nodes_tmp = network->nodes;
	while (*nodes_tmp)
	{
		if (!(*nodes_tmp)->nodes)
			error(ERR_ISOLATED_ROOM);
		nodes_tmp++;
	}
	int nodes = 0;
	while (network->nodes[nodes])
	{
		ft_printf("Node detected: Name(%s), Connections(%d)\n", network->nodes[nodes]->name, network->nodes[nodes]->connections);
		int connection = 0;
		while (network->nodes[nodes]->nodes[connection])
		{
			ft_printf("    Connects with: Name(%s)\n", network->nodes[nodes]->nodes[connection]->name);
			connection++;
		}
		nodes++;
	}
	ft_printf("%d nodes detected in network. Node %s is entry. Node %s is exit.\n", nodes, network->entry->name, network->exit->name);
	return (network);
}
