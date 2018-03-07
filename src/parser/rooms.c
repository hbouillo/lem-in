/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 03:59:29 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/07 05:45:27 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

t_room			*find_room(char *name, t_data *data)
{
	t_llist		*rooms;
	t_room		*room;
	long		name_hash;

	name_hash = djb2(name);
	rooms = data->hash_rooms[name_hash % ROOM_LISTS];
	while (rooms)
	{
		room = ((t_room *)rooms->data);
		if (name_hash == room->name_hash && ft_strequ(name, room->name))
			return (room);
		rooms = rooms->next;
	}
	return (NULL);
}

int				parse_room(char **split, t_data *data, t_cdata *cdata)
{
	t_room		*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		error(ERR_MALLOC, ERR_CRITICAL);
	room->id = data->rooms_count++;
	room->name = ft_strdup(split[0]);
	room->name_hash = djb2(room->name);
	room->pos.x = ft_atoi(split[1]);
	room->pos.y = ft_atoi(split[2]);
	if (*room->name == 'L')
		return (error(ERR_ILLEGAL_ROOM, ERR_WARNING));
	if (find_room(room->name, data))
		error(ERR_ROOM_ALREADY_EXISTS, ERR_WARNING);
	ft_llist_front(&data->rooms, ft_llist_new(room));
	ft_llist_front(data->hash_rooms + room->name_hash % ROOM_LISTS,
		ft_llist_new(room));
	if (cdata->room_type == start)
		data->start = room;
	else if (cdata->room_type == end)
		data->end = room;
	cdata->room_type = none;
	return (0);
}

void			free_room(void *room_ptr)
{
	t_room		*room;

	room = (t_room *)room_ptr;
	if (!room)
		return ;
	free(room->name);
	free(room);
}
