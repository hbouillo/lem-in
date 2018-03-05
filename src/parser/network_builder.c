/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 04:26:10 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/05 04:01:45 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static int			build_nodes(t_network *network, t_data const *const data)
{
	t_llist			*rooms;
	t_room			*room;

	network->nodes = (t_node **)ft_memalloc(sizeof(t_node *) * (data->rooms_count + 1));
	network->nodes_count = data->rooms_count;
	rooms = data->rooms;
	while (rooms)
	{
		room = ((t_room *)rooms->data);
		network->nodes[room->id] = (t_node *)ft_memalloc(sizeof(t_node));
		network->nodes[room->id]->name = ft_strdup(room->name);
		network->nodes[room->id]->pos = room->pos;
		network->nodes[room->id]->id = room->id;
		if (room->id == data->start->id)
			network->entry = network->nodes[room->id];
		else if (room->id == data->end->id)
			network->exit = network->nodes[room->id];
		verbose("    Built node Id(%d) Name(%s).\n",
			network->nodes[room->id]->id, network->nodes[room->id]->name);
		rooms = rooms->next;
	}
	return (0);
}

static void			count_connections(t_data *data, t_llist *tubes)
{
	t_tube			*tube;
	t_llist			*tubes_save;
	int				room;
	int				i;

	if (!(data->id_tubes_count = (int *)ft_memalloc(sizeof(int) * data->rooms_count)) ||
		!(data->id_tubes = (int **)ft_memalloc(sizeof(int *) * data->rooms_count)))
		error(ERR_MALLOC, ERR_CRITICAL);
	tubes_save = tubes;
	while (tubes)
	{
		tube = (t_tube *)tubes->data;
		data->id_tubes_count[tube->room1->id]++;
		data->id_tubes_count[tube->room2->id]++;
		tubes = tubes->next;
	}
	room = -1;
	while (++room < data->rooms_count)
		if (!(data->id_tubes[room] = (int *)ft_memalloc(sizeof(int) * data->id_tubes_count[room])))
			error(ERR_MALLOC, ERR_CRITICAL);
	tubes = tubes_save;
	while (tubes)
	{
		tube = (t_tube *)tubes->data;
		i = 0;
		while (data->id_tubes[tube->room1->id][i] && i < data->id_tubes_count[tube->room1->id])
			i++;
		data->id_tubes[tube->room1->id][i] = tube->room2->id;
		i = 0;
		while (data->id_tubes[tube->room2->id][i] && i < data->id_tubes_count[tube->room2->id])
			i++;
		data->id_tubes[tube->room2->id][i] = tube->room1->id;
		tubes = tubes->next;
	}
}

// static int			fill_connections(t_node *node, t_node **list_nodes,
// 						t_llist *tlist)
// {
// 	int				i;
// 	t_node			**nodes_temp;
//
// 	i = 0;
// 	while (tlist)
// 	{
// 		if (node->id == ((t_tube *)tlist->data)->room1->id ||
// 			node->id == ((t_tube *)tlist->data)->room2->id)
// 		{
// 			nodes_temp = list_nodes;
// 			while (*nodes_temp)
// 			{
// 				if ((*nodes_temp)->id != node->id &&
// 					((*nodes_temp)->id == ((t_tube *)tlist->data)->room1->id ||
// 					(*nodes_temp)->id == ((t_tube *)tlist->data)->room2->id))
// 				{
// 					node->nodes[i++] = (*nodes_temp);
// 				}
// 				nodes_temp++;
// 			}
// 		}
// 		tlist = tlist->next;
// 	}
// 	return (0);
// }

static int			fill_connections(t_node *node, t_node **list_nodes,
						t_data *data)
{
	int				i;

	i = -1;
	while (++i < node->connections)
		node->nodes[i] = list_nodes[data->id_tubes[node->id][i]];
	return (0);
}

static void			remove_double_links(t_network *network)
{
	t_node			**nodes;
	int				i;
	int				j;

	nodes = network->nodes;
	while (*nodes)
	{
		i = -1;
		while (++i < (*nodes)->connections)
		{
			j = -1;
			while (++j < (*nodes)->connections)
			{
				if ((*nodes)->nodes[i] && i != j &&
					(*nodes)->nodes[i] == (*nodes)->nodes[j])
					{
						error(ERR_TUBE_ALREADY_EXISTS, ERR_WARNING);
						(*nodes)->nodes[i] = NULL;
					}
			}
		}
		nodes++;
	}
}

static int			link_nodes(t_network *network, t_data *data)
{
	t_node			**nodes;
	t_llist			*tlist;
	int				i;

	nodes = network->nodes;
	tlist = data->tubes;
	count_connections(data, tlist);
	while (*nodes)
	{
		tlist = data->tubes;
		(*nodes)->connections = data->id_tubes_count[(*nodes)->id];
		(*nodes)->nodes = (t_node **)ft_memalloc(
			sizeof(t_node *) * ((*nodes)->connections + 1));
		fill_connections(*nodes, network->nodes, data);
		i = -1;
		verbose("    Linked node Id(%d) Name(%s) to %d nodes.\n",
			(*nodes)->id, (*nodes)->name, (*nodes)->connections);
		nodes++;
	}
	remove_double_links(network);
	return (0);
}

t_network			*build_network(t_data *data)
{
	t_network		*net;
	t_node			**nodes_tmp;
	int				nodes;

	net = (t_network *)ft_memalloc(sizeof(t_network));
	net->units = data->ants;
	build_nodes(net, data);
	link_nodes(net, data);
	nodes_tmp = net->nodes - 1;
	while (*(++nodes_tmp))
		if (!(*nodes_tmp)->nodes)
			error(ERR_ISOLATED_ROOM, ERR_WARNING);
	nodes = -1;
	return (net);
}
