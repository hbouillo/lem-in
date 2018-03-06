/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 04:49:11 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/06 06:48:19 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		count_paths(t_path *paths)
{
	int			count;

	count = 0;
	while (paths->length)
	{
		count++;
		paths++;
	}
	return (count);
}

void			run_ants(int ants, t_path *paths)
{
	int			paths_count;
	int			keep;
	int			i;
	int			j;
	int			cycles;
	int			ant;

	paths_count = count_paths(paths);
	keep = 1;
	cycles = 1;
	while (keep)
	{
		keep = 0;
		i = -1;
		ft_putchar('\n');
		while (++i < paths_count)
		{
			j = 0;
			while (++j < paths[i].length)
			{
				ant = (cycles - j) * paths_count + i + 1;
				if (ant <= ants && ant > 0)
				{
					keep = 1;
					ft_printf("L%d-%s ", ant, paths[i].nodes[j]);
				}
			}
		}
		cycles++;
	}
}
