/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 04:26:10 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/21 16:46:29 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static int			build_nodes(t_network *network, t_data const *const data)
{
	t_llist			*rooms;
	t_room			*room;

	if (!(network->nodes = (t_node **)ft_memalloc(
		sizeof(t_node *) * (data->rooms_count + 1))))
		exit(1);
	network->nodes_count = data->rooms_count;
	rooms = data->rooms;
	while (rooms)
	{
		room = ((t_room *)rooms->data);
		if (!(network->nodes[room->id] = (t_node *)ft_memalloc(sizeof(t_node)))
			|| !(network->nodes[room->id]->name = ft_strdup(room->name)))
			exit(1);
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

static int			link_nodes(t_network *network, t_data *data)
{
	t_node			**nodes;
	t_llist			*tlist;
	int				i;

	nodes = network->nodes;
	tlist = data->tubes;
	process_data(data, tlist);
	while (*nodes)
	{
		tlist = data->tubes;
		(*nodes)->connections = data->id_tubes_count[(*nodes)->id];
		if (!((*nodes)->nodes = (t_node **)ft_memalloc(
			sizeof(t_node *) * ((*nodes)->connections + 1))))
			exit(1);
		fill_connections(*nodes, network->nodes, data);
		remove_double_links(*nodes);
		i = -1;
		verbose("    Linked node Id(%d) Name(%s) to %d nodes.\n",
			(*nodes)->id, (*nodes)->name, (*nodes)->connections);
		nodes++;
	}
	return (0);
}

t_network			*build_network(t_data *data)
{
	t_network		*net;
	t_node			**nodes_tmp;
	int				nodes;

	if (!(net = (t_network *)ft_memalloc(sizeof(t_network))))
		exit(1);
	build_nodes(net, data);
	link_nodes(net, data);
	nodes_tmp = net->nodes - 1;
	while (*(++nodes_tmp))
		if (!(*nodes_tmp)->nodes)
			error(ERR_ISOLATED_ROOM, ERR_WARNING);
	nodes = -1;
	return (net);
}
