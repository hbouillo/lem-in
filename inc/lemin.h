/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:25:25 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/30 22:09:52 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdlib.h>

# define ERR_NEG_ANTS 10
# define ERR_TUBE_UNKNOWN_ROOM 11
# define ERR_FORMAT_UNKNOWN 20
# define ERR_FORMAT_ROOM 21
# define ERR_FORMAT_TUBE 22

# define TEST(X) ft_printf("Test %d\n", X)

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_room
{
	char			*name;
	t_pos			pos;
}					t_room;

typedef struct		s_rlist
{
	t_room			*room;
	struct s_rlist	*next;
}					t_rlist;

typedef struct		s_tube
{
	t_room			*room1;
	t_room			*room2;
}					t_tube;

typedef struct		s_tlist
{
	t_tube			*tube;
	struct s_tlist	*next;
}					t_tlist;

typedef struct		s_data
{
	int				ants;
	t_rlist			*rooms;
	t_tlist			*tubes;
	t_room			*start;
	t_room			*end;
}					t_data;

void			error(int exitcode);

t_data			*parse_data(void);

#endif
