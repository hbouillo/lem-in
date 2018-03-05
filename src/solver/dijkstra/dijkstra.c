/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 03:36:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/05 02:36:28 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dijkstra.h"

static void			add_updated_dnode(t_dijkstra *dijkstra, t_dnode *dnode)
{
	dijkstra->states[dnode->node->id] |= IN_UPDATED;
	ft_llist_front(&dijkstra->updated_dnodes, ft_llist_new(dnode));
	dijkstra->dnode_array[dnode->node->id] = dnode;
}

static void			add_subgraph_dnode(t_dijkstra *dijkstra, t_dnode *dnode)
{
	dijkstra->states[dnode->node->id] |= IN_SUBGRAPH;
	ft_llist_front(&dijkstra->subgraph, ft_llist_new(dnode));
}

static void			update_node(t_dijkstra *dijkstra)
{
	t_dnode			*to_update;
	t_dnode			*tmp_dnode;
	int				i;

	to_update = (t_dnode *)dijkstra->subgraph->data;
	i = -1;
	while (++i < to_update->node->connections)
	{
		if (!to_update->node->nodes[i])
			continue ;
		if (!(tmp_dnode = dijkstra->dnode_array[to_update->node->nodes[i]->id]))
		{
			tmp_dnode = new_dnode(to_update->node->nodes[i]);
			add_updated_dnode(dijkstra, tmp_dnode);
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
		if ((!dnode || dnode->dist > tmp_dnode->dist)
			&& !(dijkstra->states[tmp_dnode->node->id] & IN_SUBGRAPH))
			dnode = tmp_dnode;
		tmp = tmp->next;
	}
	if (dnode)
		verbose("Selected room Id(%d), Name(%s)\n", dnode->node->id,
		dnode->node->name);
	return (dnode);
}

void				find_shortest_path(t_path *path, t_network *network)
{
	t_dijkstra		dijkstra;
	t_dnode			*tmp;

	ft_bzero(&dijkstra, sizeof(t_dijkstra));
	if (!(dijkstra.states = (char *)ft_memalloc(sizeof(char) * network->nodes_count)))
		error(ERR_MALLOC, ERR_CRITICAL);
	if (!(dijkstra.dnode_array = (t_dnode **)ft_memalloc(sizeof(t_dnode *) * network->nodes_count)))
		error(ERR_MALLOC, ERR_CRITICAL);
	add_updated_dnode(&dijkstra, new_dnode(network->entry));
	((t_dnode *)dijkstra.updated_dnodes->data)->dist = 0;
	while (!dijkstra.subgraph ||
		((t_dnode *)dijkstra.subgraph->data)->node != network->exit)
	{
		tmp = select_node(&dijkstra);
		if (!tmp)
		{
			verbose("Couldn't find any path.\n");
			return ;
		}
		add_subgraph_dnode(&dijkstra, tmp);
		update_node(&dijkstra);
	}
	build_path(dijkstra, path);
	verbose("Found shortest path.\n");
	free_dijkstra(dijkstra);
}
