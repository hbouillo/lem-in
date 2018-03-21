/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 02:54:41 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/21 17:26:04 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

int				count_real_connections(t_node *node)
{
	int			real;
	int			i;

	real = 0;
	i = -1;
	while (++i < node->connections)
		if (node->nodes[i])
			real++;
	return (real);
}

t_path			*solve(t_network *network, int max_paths_param, int max_length)
{
	int			max_paths;
	int			paths_found;
	t_path		*paths;

	max_paths = ft_nbrmin(count_real_connections(network->entry),
						count_real_connections(network->exit));
	sverbose("At most %d paths can be found.\n", max_paths);
	if (max_paths_param)
	{
		max_paths = ft_nbrmin(max_paths, max_paths_param);
		sverbose("Restricting maximum paths to %d.\n", max_paths);
	}
	if (max_length)
		sverbose("Restricting maximum path length to %d.\n", max_length);
	if (!(paths = (t_path *)ft_memalloc(sizeof(t_path) * (max_paths + 1))))
		error(ERR_MALLOC, ERR_CRITICAL);
	paths_found = -1;
	while (++paths_found < max_paths &&
			find_shortest_path(paths, network, max_length))
	{
		sverbose("    Found path %d/%d (%d tubes). ",
			paths_found + 1, max_paths, paths[paths_found].length - 1);
		sverbose_path(paths[paths_found]);
	}
	return (paths);
}
