/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 07:07:26 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/07 05:50:06 by hbouillo         ###   ########.fr       */
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

# define IN_SUBGRAPH 0xF0
# define IN_UPDATED 0x0F

typedef struct		s_dijkstra
{
	char			*states;
	t_dnode			**dnode_array;
	t_llist			*updated_dnodes;
	t_llist			*subgraph;
}					t_dijkstra;

t_dnode				*new_dnode(t_node *node);

void				extract_path(t_dijkstra dijkstra, t_path *path);

void				free_dijkstra(t_dijkstra dijkstra);

void				add_subgraph_dnode(t_dijkstra *dijkstra, t_dnode *dnode);
void				add_updated_dnode(t_dijkstra *dijkstra, t_dnode *dnode);

#endif
