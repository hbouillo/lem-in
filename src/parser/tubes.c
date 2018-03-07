/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tubes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 19:04:44 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/07 05:45:15 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

int				parse_tube(char **split, t_data *data, t_cdata *cdata)
{
	t_tube		*tube;

	cdata = NULL;
	if (!(tube = (t_tube *)malloc(sizeof(t_tube))))
		error(ERR_MALLOC, ERR_CRITICAL);
	tube->room1 = find_room(split[0], data);
	tube->room2 = find_room(split[1], data);
	if (!tube->room1 || !tube->room2)
	{
		error(ERR_TUBE_UNKNOWN_ROOM, ERR_WARNING);
		return (1);
	}
	if (tube->room1->id == tube->room2->id)
	{
		error(ERR_TUBE_SAME_ROOM, ERR_WARNING);
		return (1);
	}
	ft_llist_front(&data->tubes, ft_llist_new(tube));
	return (0);
}

void			free_tube(void *tube_ptr)
{
	t_tube		*tube;

	tube = (t_tube *)tube_ptr;
	if (!tube)
		return ;
	free(tube);
}
