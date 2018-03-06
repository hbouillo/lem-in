/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 02:54:41 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/06 05:06:36 by hbouillo         ###   ########.fr       */
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

t_path			*solve(t_network *network)
{
	int			max_paths;
	int			paths_found;
	t_path		*paths;

	paths_found = 0;
	max_paths = ft_nbrmin(count_real_connections(network->entry),
						count_real_connections(network->exit));
	verbose("At most %d paths can be found.\n", max_paths);
	if (!(paths = (t_path *)ft_memalloc(sizeof(t_path) * (max_paths + 1))))
		error(ERR_MALLOC, ERR_CRITICAL);
	while (paths_found < max_paths && find_shortest_path(paths, network))
		paths_found++;
	return (paths);
}
