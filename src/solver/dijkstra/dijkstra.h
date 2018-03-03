/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 07:07:26 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 07:09:35 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIJKSTRA_H
# define DIJKSTRA_H

# include "../solver.h"

typedef struct		s_dnode
{
	int				dist;
	t_node			*node;
	struct s_dnode	*path;
}					t_dnode;

typedef struct		s_dijkstra
{
	t_llist			*updated_dnodes;
	t_llist			*subgraph;
}					t_dijkstra;

t_dnode				*new_dnode(t_node *node);

void				build_path(t_dijkstra dijkstra, t_path *path);

void				free_dijkstra(t_dijkstra dijkstra);

t_dnode				*list_get_node_elem(t_llist *list, t_node *node);

#endif
