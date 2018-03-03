/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 02:54:41 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 07:04:24 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"

t_path			*solve(t_network *network)
{
	t_path		*shortest_path;

	if (!(shortest_path = (t_path *)ft_memalloc(sizeof(t_path))))
		error(ERR_MALLOC, ERR_CRITICAL);
	find_shortest_path(shortest_path, network);
	return (shortest_path);
}
