/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:34:38 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:55:12 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_gnl.h"

/*
** Returns a fresh intitialized header
*/

static t_reader			*init_reader(void)
{
	t_reader			*reader;

	if (!(reader = (t_reader *)ft_memalloc(sizeof(t_reader))))
		return (NULL);
	reader->bgn = reader->buf + BUFF_SIZE;
	reader->end = reader->bgn;
	reader->eof = -1;
	reader->ret = BUFF_SIZE;
	return (reader);
}

/*
** Reads the next line on the given file descriptor.
**
** [ Args ]	fd: the file descriptor of the file to read
**			line: pointer on a char*, where the line will be set
** [Return]	Status code (GNL_ERR, GNL_EOL, GNL_EOF)
*/

int						ft_gnl(const int fd, char **line)
{
	static t_reader		*rd[OPEN_MAX];

	if (fd < 0 || fd > OPEN_MAX || (!(rd[fd]) && !(rd[fd] = init_reader()))
		|| !line || !(*line = (char *)ft_strnew(0)))
		return (GNL_ERR);
	while (1)
	{
		while (rd[fd]->end < rd[fd]->buf + rd[fd]->ret && *rd[fd]->end != '\n')
			rd[fd]->end++;
		if (!(*line = ft_strfjoin(*line,
				ft_strsub(rd[fd]->bgn, 0, (int)(rd[fd]->end - rd[fd]->bgn)))))
			return (GNL_ERR);
		rd[fd]->bgn = rd[fd]->end + 1;
		if (rd[fd]->end < rd[fd]->buf + rd[fd]->ret && *(rd[fd]->end++) == '\n')
			return (GNL_EOL);
		rd[fd]->end = rd[fd]->buf;
		rd[fd]->bgn = rd[fd]->end;
		if ((rd[fd]->ret = read(fd, rd[fd]->buf, BUFF_SIZE)) == 0)
			return ((rd[fd]->eof++ >= 0 || !ft_strlen(*line))
					? GNL_EOF : GNL_EOL);
		else if (rd[fd]->ret < 0)
			return (GNL_ERR);
	}
}
