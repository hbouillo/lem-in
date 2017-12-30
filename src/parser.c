/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:28:07 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/30 22:13:15 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

//TODO: ERRORS

static t_room	*find_room(char *name, t_data *data)
{
	t_rlist *rooms;

	rooms = data->rooms;
	while (rooms)
	{
		if (ft_strequ(name, rooms->room->name))
			return (rooms->room);
		rooms = rooms->next;
	}
	return (NULL);
}

static t_tube	*parse_tube(char **split, t_data *data)
{
	t_tube		*tube;

	tube = (t_tube *)malloc(sizeof(t_tube));
	tube->room1 = find_room(split[0], data);
	tube->room2 = find_room(split[1], data);
	if (!tube->room1 || !tube->room2)
		error(ERR_TUBE_UNKNOWN_ROOM);
	ft_printf("Tube parsed: from(%s) to(%s)\n", tube->room1->name, tube->room2->name);
	return (tube);
}

static t_room	*parse_room(char **split, t_data *data)
{
	t_room		*room;
	int			i;
	t_rlist		*rooms;

	rooms = data->rooms;
	room = (t_room *)malloc(sizeof(t_room));
	room->name = ft_strdup(split[0]);
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
	ft_printf("Room parsed: name(%s) pos(%d, %d)\n", room->name, room->pos.x, room->pos.y);
	return (room);
}

int				*parse_line(char *line, t_data *data)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	if (ft_chartablen(split) == 3)
	{
		parse_room(split, data);
	}
	else
	{
		ft_chartabfree(split);
		split = ft_strsplit(line, '-');
		if (ft_chartablen(split) == 2)
		{
			parse_tube(split, data);
		}
		else
			error(ERR_FORMAT_UNKNOWN);
	}
	ft_chartabfree(split);
	return (0);
}

t_data			*parse_data(void)
{
	t_data		*data;
	int			parsed_ants;
	char		*line;

	data = (t_data *)malloc(sizeof(t_data));
	data->rooms = NULL;
	data->tubes = NULL;
	parsed_ants = 0;
	while (ft_gnl(0, &line) > 0)
	{
		if (!parsed_ants)
		{
			data->ants = ft_atoi(line);
			if (data->ants < 0)
				error(ERR_NEG_ANTS);
			parsed_ants = 1;
		}
		else
		{
			parse_line(line, data);
		}
		free(line);
	}
	return (data);
}
