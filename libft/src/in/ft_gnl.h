/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:58:13 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 06:55:43 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define GNL_EOL 1
# define GNL_EOF 0
# define GNL_ERR -1

# define BUFF_SIZE 4096

typedef struct		s_reader
{
	int				ret;
	int				eof;
	char			*bgn;
	char			*end;
	char			buf[BUFF_SIZE + 1];
}					t_reader;

/*
** Reads the next line on the given file descriptor.
**
** [ Args ]	fd: the file descriptor of the file to read
**			line: pointer on a char*, where the line will be set
** [Return]	Status code (GNL_ERR, GNL_EOL, GNL_EOF)
*/

int					get_next_line(const int fd, char **line);

#endif
