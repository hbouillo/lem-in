/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:28:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/03 05:58:11 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

static t_tube	*parse_tube(char **split, t_data *data, t_cdata *cdata)
{
	t_tube		*tube;

	tube = (t_tube *)malloc(sizeof(t_tube));
	tube->room1 = find_room(split[0], data);
	tube->room2 = find_room(split[1], data);
	if (!tube->room1 || !tube->room2)
		error(ERR_TUBE_UNKNOWN_ROOM);
	place_tube(tube, data);
	return (tube);
}

static int		*parse_line(char *line, t_data *data, t_cdata *cdata)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	if (ft_chartablen(split) == 3)
	{
		parse_room(split, data, cdata);
	}
	else
	{
		ft_chartabfree(split);
		split = ft_strsplit(line, '-');
		if (ft_chartablen(split) == 2)
		{
			parse_tube(split, data, cdata);
		}
		else
			error(ERR_FORMAT_UNKNOWN);
	}
	ft_chartabfree(split);
	return (0);
}

static int		*parse_command(char *line, t_data *data, t_cdata *cdata)
{
	char		**split;

	if (*line != '#' || ft_strlen(line) < 2 || line[1] != '#')
	{
		return (0);
	}
	line += 2;
	split = ft_strsplit(line, ' ');
	if (ft_strequ(split[0], "start"))
		cdata->room_type = start;
	else if (ft_strequ(split[0], "end"))
		cdata->room_type = end;
	ft_chartabfree(split);
	return (0);
}

t_data			*parse_data(void)
{
	t_data		*data;
	t_cdata		*cdata;
	int			parsed_ants;
	char		*line;

	cdata = (t_cdata *)ft_memalloc(sizeof(t_cdata));
	data = (t_data *)ft_memalloc(sizeof(t_data));
	parsed_ants = 0;
	while (ft_gnl(0, &line) > 0)
	{
		if (!parsed_ants)
		{
			data->ants = ft_atoi(line);
			if (data->ants <= 0)
				error(ERR_NEG_OR_NUL_ANTS);
			parsed_ants = 1;
		}
		else if (*line == '#')
			parse_command(line, data, cdata);
		else
			parse_line(line, data, cdata);
		free(line);
	}
	return (data);
}
