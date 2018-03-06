/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:25:25 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/06 06:59:19 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include <stdlib.h>

# define ERR_MALLOC 01,"Malloc failed."
# define ERR_NO_START_NODE 10,"No entry node has been specified."
# define ERR_NO_END_NODE 11,"No exit node has been specified"
# define ERR_NEG_OR_NUL_ANTS 12,"Negative or nul amount of ants."
# define ERR_ISOLATED_ROOM 13,"At least one node is isolated"
# define ERR_ROOM_ALREADY_EXISTS 14,"Node already exists."
# define ERR_ILLEGAL_ROOM 15,"Illegal room name."
# define ERR_TUBE_UNKNOWN_ROOM 16,"Tube trying to connect an unknown room"
# define ERR_TUBE_SAME_ROOM 17,"Tube trying to connect a room with itself"
# define ERR_TUBE_ALREADY_EXISTS 18,"Tube already exists."
# define ERR_FORMAT_UNKNOWN 20,"Unknown line format."
# define ERR_FORMAT_ROOM 21,"Unknown room line format."
# define ERR_FORMAT_TUBE 22,"Unknown tube line format."

# define ERR_CRITICAL "Error", 1
# define ERR_WARNING "Warning", 0

# define ARG_VERBOSE 0

# define V_COLOR 0x1c6f93

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
	int				id;
	char			*name;
	long			name_hash;
	t_pos			pos;
}					t_room;

typedef enum		e_rtype
{
	none,
	start,
	end
}					t_rtype;

typedef struct		s_tube
{
	t_room			*room1;
	t_room			*room2;
}					t_tube;

#define ROOM_LISTS 10000

typedef struct		s_data
{
	int				ants;
	int				rooms_count;
	t_llist			*rooms;
	t_llist			*tubes;
	t_room			*start;
	t_room			*end;
	int				*id_tubes_count;
	int				**id_tubes;
	t_llist			*hash_rooms[ROOM_LISTS];
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
	int				id;
	int				hidden;
	int				connections;
	struct s_node	**nodes;
	char			*name;
	t_pos			pos;
}					t_node;

typedef struct		s_network
{
	int				nodes_count;
	t_node			**nodes;
	t_node			*entry;
	t_node			*exit;
}					t_network;

typedef struct		s_path
{
	int				length;
	char			**nodes;
}					t_path;

/*
** Functions
*/

int					error(int errcode, char const *const errmsg, char *errtype,
						int errexit);
int					verbose(char *str, ...);
void				verbose_path(t_path path);

t_data				*parse_data(void);

t_network			*build_network(t_data *data);

t_path				*solve(t_network *network);

void				run_ants(int ants, t_path *paths);

void				free_room(void *room);
void				free_tube(void *room);

long				djb2(char const *str);

#endif
