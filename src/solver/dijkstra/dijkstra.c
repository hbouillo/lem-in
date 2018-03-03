/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 03:36:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 07:19:20 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dijkstra.h"

static void			update_node(t_dijkstra *dijkstra)
{
	t_dnode			*to_update;
	t_dnode			*tmp_dnode;
	int				i;

	to_update = (t_dnode *)dijkstra->subgraph->data;
	i = -1;
	while (++i < to_update->node->connections)
	{
		if (!(tmp_dnode = list_get_node_elem(dijkstra->updated_dnodes,
			to_update->node->nodes[i])))
		{
			tmp_dnode = new_dnode(to_update->node->nodes[i]);
			ft_llist_front(&dijkstra->updated_dnodes, ft_llist_new(tmp_dnode));
		}
		if (tmp_dnode->dist < 0 || tmp_dnode->dist > to_update->dist + 1)
		{
			tmp_dnode->path = to_update;
			tmp_dnode->dist = to_update->dist + 1;
		}
	}
}

static t_dnode		*select_node(t_dijkstra *dijkstra)
{
	t_dnode			*dnode;
	t_llist			*tmp;
	t_dnode			*tmp_dnode;

	dnode = NULL;
	tmp = dijkstra->updated_dnodes;
	while (tmp)
	{
		tmp_dnode = (t_dnode *)tmp->data;
		if (!dnode || dnode->dist > tmp_dnode->dist)
			dnode = ft_llist_has_data(dijkstra->subgraph, tmp_dnode) ?
				dnode : tmp_dnode;
		tmp = tmp->next;
	}
	if (dnode)
		verbose("Selected room Name(%s)\n", dnode->node->name);
	return (dnode);
}

void				find_shortest_path(t_path *path, t_network *network)
{
	t_dijkstra		dijkstra;
	t_dnode			*tmp;

	ft_bzero(&dijkstra, sizeof(t_dijkstra));
	ft_llist_front(&dijkstra.updated_dnodes,
		ft_llist_new(new_dnode(network->entry)));
	((t_dnode *)dijkstra.updated_dnodes->data)->dist = 0;
	while (!dijkstra.subgraph ||
		((t_dnode *)dijkstra.subgraph->data)->node != network->exit)
	{
		tmp = select_node(&dijkstra);
		if (!tmp)
		{
			path->length = -1;
			verbose("Couldn't find any path.\n");
			return ;
		}
		ft_llist_front(&dijkstra.subgraph, ft_llist_new(tmp));
		update_node(&dijkstra);
	}
	build_path(dijkstra, path);
	verbose("Found shortest path.\n");
	free_dijkstra(dijkstra);
}
