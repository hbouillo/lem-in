/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 03:59:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/03 05:11:21 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room			*find_room(char *name, t_data *data)
{
	t_rlist		*rooms;

	rooms = data->rooms;
	while (rooms)
	{
		if (ft_strequ(name, rooms->room->name))
			return (rooms->room);
		rooms = rooms->next;
	}
	return (NULL);
}

static int		place_room(t_room *room, t_data *data)
{
	t_rlist		*rooms;

	rooms = data->rooms;
	if (!rooms)
	{
		rooms = (t_rlist *)malloc(sizeof(t_rlist));
		rooms->room = room;
		rooms->next = NULL;
		data->rooms = rooms;
	}
	else
	{
		while (rooms->next)
			rooms = rooms->next;
		rooms->next = (t_rlist *)malloc(sizeof(t_rlist));
		rooms->next->room = room;
		rooms->next->next = NULL;
	}
	return (0);
}

int				*parse_room(char **split, t_data *data, t_cdata *cdata)
{
	t_room		*room;

	room = (t_room *)malloc(sizeof(t_room));
	room->name = ft_strdup(split[0]);
	room->pos.x = ft_atoi(split[1]);
	room->pos.y = ft_atoi(split[2]);
	if (find_room(room->name, data))
		error(ERR_ROOM_ALREADY_EXISTS);
	place_room(room, data);
	if (cdata->room_type == start)
		data->start = room;
	else if (cdata->room_type == end)
		data->end = room;
	cdata->room_type = none;
	return (0);
}
