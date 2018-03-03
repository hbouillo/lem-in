/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tubes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:04:44 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 03:09:06 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static int		place_tube(t_tube *tube, t_data *data)
{
	t_tlist		*tubes;

	tubes = data->tubes;
	if (!tubes)
	{
		tubes = (t_tlist *)malloc(sizeof(t_tlist));
		tubes->tube = tube;
		tubes->next = NULL;
		data->tubes = tubes;
	}
	else
	{
		while (tubes->next)
			tubes = tubes->next;
		tubes->next = (t_tlist *)malloc(sizeof(t_tlist));
		tubes->next->tube = tube;
		tubes->next->next = NULL;
	}
	return (0);
}

int				parse_tube(char **split, t_data *data, t_cdata *cdata)
{
	t_tube		*tube;
	t_tlist		*tubes;

	cdata = NULL;
	tube = (t_tube *)malloc(sizeof(t_tube));
	tube->room1 = find_room(split[0], data);
	tube->room2 = find_room(split[1], data);
	if (!tube->room1 || !tube->room2)
	{
		error(ERR_TUBE_UNKNOWN_ROOM, ERR_WARNING); //TODO: Fin acquisition ?
		return (1);
	}
	if (ft_strequ(tube->room1->name, tube->room2->name))
	{
		error(ERR_TUBE_SAME_ROOM_CONNECTION, ERR_WARNING); //TODO: Fin acquisition ?
		return (1);
	}
	tubes = data->tubes;
	while (tubes)
	{
		if ((ft_strequ(tubes->tube->room1->name, tube->room1->name) &&
			ft_strequ(tubes->tube->room2->name, tube->room2->name)) ||
			(ft_strequ(tubes->tube->room2->name, tube->room1->name) &&
			ft_strequ(tubes->tube->room1->name, tube->room2->name)))
			{
				error(ERR_TUBE_ALREADY_EXISTS, ERR_WARNING); //TODO: Fin acquisition ?
				return (1);
			}
		tubes = tubes->next;
	}
	place_tube(tube, data);
	return (0);
}

void			free_tlist(t_tlist *tube)
{
	if (!tube)
		return ;
	free_tlist(tube->next);
	free(tube->tube);
	free(tube);
}
