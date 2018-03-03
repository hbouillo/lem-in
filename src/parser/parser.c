/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:28:07 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 03:17:49 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static int		parse_line(char *line, t_data *data, t_cdata *cdata)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	if (ft_chartablen(split) == 3)
	{
		verbose("node\n");
		parse_room(split, data, cdata);
	}
	else
	{
		verbose("tube\n");
		ft_chartabfree(split);
		split = ft_strsplit(line, '-');
		if (ft_chartablen(split) == 2)
		{
			parse_tube(split, data, cdata);
		}
		else
		{
			error(ERR_FORMAT_UNKNOWN, ERR_WARNING);
			return (1);
		}
	}
	ft_chartabfree(split);
	return (0);
}

static void		parse_command(char *line, t_data *data, t_cdata *cdata)
{
	char		**split;

	data = NULL;
	if (*line != '#' || ft_strlen(line) < 2 || line[1] != '#')
	{
		if (*line == '#')
			verbose("comment\n");
		return ;
	}
	verbose("command");
	line += 2;
	split = ft_strsplit(line, ' ');
	if (ft_strequ(split[0], "start"))
		cdata->room_type = start;
	else if (ft_strequ(split[0], "end"))
		cdata->room_type = end;
	else
		verbose(" ignored");
	verbose("\n");
	ft_chartabfree(split);
}

static int		parse_ants(int *parsed_ants, t_data *data, char *line)
{
	if (*parsed_ants)
		return (0);
	verbose("ants\n");
	data->ants = ft_atoi(line);
	if (data->ants <= 0)
		error(ERR_NEG_OR_NUL_ANTS, ERR_CRITICAL);
	*parsed_ants = 1;
	return (1);
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
		verbose("%-50s ", line);
		if (parse_ants(&parsed_ants, data, line))
			continue;
		parse_command(line, data, cdata);
		if (*line != '#' && parse_line(line, data, cdata))
			break ;
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	free(cdata);
	return (data);
}
