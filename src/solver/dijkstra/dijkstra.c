/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 03:36:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/07 05:19:29 by hbouillo         ###   ########.fr       */
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

static void			update_node(t_dijkstra *dijkstra, int max_dist)
{
	t_dnode			*to_update;
	t_dnode			*tmp_dnode;
	int				i;

	to_update = (t_dnode *)dijkstra->subgraph->data;
	if (max_dist > 1 && to_update->dist >= max_dist)
		return;
	i = -1;
	while (++i < to_update->node->connections)
	{
		if (!to_update->node->nodes[i] || to_update->node->nodes[i]->hidden)
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
		verbose("    Selected room Id(%d), Name(%s)\n", dnode->node->id,
		dnode->node->name);
	return (dnode);
}

int					find_shortest_path(t_path *path, t_network *network,
						int max_length)
{
	static t_dijkstra		dijkstra;
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
			sverbose("No more path could be found.\n");
			return (0);
		}
		add_subgraph_dnode(&dijkstra, tmp);
		update_node(&dijkstra, max_length);
	}
	extract_path(dijkstra, path);
	free_dijkstra(dijkstra);
	return (1);
}
