/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 07:06:50 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/06 05:57:07 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dijkstra.h"

t_dnode				*new_dnode(t_node *node)
{
	t_dnode			*dnode;

	if (!(dnode = (t_dnode *)ft_memalloc(sizeof(t_dnode))))
		error(ERR_MALLOC, ERR_CRITICAL);
	dnode->node = node;
	dnode->dist = -1;
	return (dnode);
}

void				extract_path(t_dijkstra dijkstra, t_path *path)
{
	t_dnode			*dnode;
	int				i;

	while (path->length)
		path++;
	ft_bzero(path, sizeof(t_path));
	dnode = ((t_dnode *)dijkstra.subgraph->data);
	while (dnode)
	{
		path->length++;
		dnode = dnode->path;
	}
	if (!(path->nodes = (char **)ft_memalloc(sizeof(char *) * path->length)))
		exit(1);
	i = path->length;
	dnode = ((t_dnode *)dijkstra.subgraph->data);
	while (dnode)
	{
		path->nodes[--i] = ft_strdup(dnode->node->name);
		if (dnode->path && dnode != dijkstra.subgraph->data)
			dnode->node->hidden = 1;
		dnode = dnode->path;
	}
}

void				free_dijkstra(t_dijkstra dijkstra)
{
	ft_llist_del(&dijkstra.updated_dnodes, &free);
	ft_llist_del(&dijkstra.subgraph, NULL);
	free(dijkstra.states);
	free(dijkstra.dnode_array);
}
