/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:28:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/03 23:58:40 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

	data = NULL;
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
		line = NULL;
	}
	if (line)
		free(line);
	free(cdata);
	return (data);
}
