/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 04:49:11 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/28 18:04:18 by hbouillo         ###   ########.fr       */
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

int				print_cycle(int cycle, int ants, int paths_count, t_path *paths)
{
	int			keep;
	int			space;
	int			ant;
	int			i;
	int			j;

	keep = 0;
	space = 0;
	i = -1;
	while (++i < paths_count)
	{
		j = 0;
		while (++j < paths[i].length)
		{
			ant = (cycle - j) * paths_count + i + 1;
			if (ant <= ants && ant > 0)
			{
				keep = 1;
				if (space || (space++ && !space))
					ft_putchar(' ');
				ft_printf("L%d-%s", ant, paths[i].nodes[j]);
			}
		}
	}
	return (keep);
}

void			run_ants(int ants, t_path *paths)
{
	int			paths_count;
	int			keep;
	int			cycles;

	paths_count = count_paths(paths);
	if (!paths_count)
	{
		ft_putchar('\n');
		error(ERR_NO_SOLUTION, ERR_CRITICAL);
	}
	keep = 1;
	cycles = 1;
	while (keep)
	{
		keep = 0;
		ft_putchar('\n');
		keep = print_cycle(cycles, ants, paths_count, paths);
		cycles++;
	}
}
