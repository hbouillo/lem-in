/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:25:25 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/04 00:14:39 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdlib.h>

# define ERR_NO_START_NODE 10,"No entry node has been specified."
# define ERR_NO_END_NODE 11,"No exit node has been specified"
# define ERR_NEG_OR_NUL_ANTS 12,"Negative or nul amount of ants."
# define ERR_ISOLATED_ROOM 13,"At least one node is isolated"
# define ERR_ROOM_ALREADY_EXISTS 14,"Node already exists."
# define ERR_TUBE_UNKNOWN_ROOM 15,"Tube is trying to connect at least one unknown room."
# define ERR_TUBE_SAME_ROOM_CONNECTION 16,"Tube is trying to connect a room with itself."
# define ERR_TUBE_ALREADY_EXISTS 17,"Tube already exists."
# define ERR_FORMAT_UNKNOWN 20,"Unknown line format."
# define ERR_FORMAT_ROOM 21,"Unknown room line format."
# define ERR_FORMAT_TUBE 22,"Unknown tube line format."

# define TEST(X) ft_printf("Test %d\n", X)

/*
** Generic structures
*/

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

/*
** Parsing structures
*/

typedef struct		s_room
{
	char			*name;
	t_pos			pos;
}					t_room;

typedef enum		e_rtype
{
	none,
	start,
	end
}					t_rtype;

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

typedef struct		s_cdata
{
	t_rtype			room_type;
}					t_cdata;

/*
** Usable data structures
*/

typedef struct		s_node
{
	int				connections;
	struct s_node	**nodes;
	int				*distances;
	char			*name;
	t_pos			pos;
}					t_node;

typedef struct		s_network
{
	int				units;
	int				nodes_count;
	t_node			**nodes;
	t_node			*entry;
	t_node			*exit;
}					t_network;

/*
** Functions
*/

void				error(int errcode, char const *const errmsg);

t_data				*parse_data(void);
int					*parse_room(char **split, t_data *data, t_cdata *cdata);
int					*parse_tube(char **split, t_data *data, t_cdata *cdata);

t_room				*find_room(char *name, t_data *data);

t_network			*build_network(t_data *data);

void				free_rlist(t_rlist *room);
void				free_tlist(t_tlist *room);

#endif
