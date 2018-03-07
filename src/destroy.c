/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 05:41:17 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/07 05:42:27 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			free_data(t_data *data)
{
	int			i;

	i = -1;
	while (++i < data->rooms_count)
		free(data->id_tubes[i]);
	i = -1;
	while (++i < ROOM_LISTS)
		ft_llist_del(data->hash_rooms + i, NULL);
	free(data->id_tubes_count);
	free(data->id_tubes);
	ft_llist_del(&data->rooms, &free_room);
	ft_llist_del(&data->tubes, &free_tube);
	free(data);
}

void			free_network(t_network *network)
{
	t_node		**nodes_temp;

	nodes_temp = network->nodes;
	while (*nodes_temp)
	{
		free((*nodes_temp)->name);
		free((*nodes_temp)->nodes);
		free(*nodes_temp);
		nodes_temp++;
	}
	free(network->nodes);
	free(network);
}

void			free_paths(t_path *paths)
{
	int			i;
	int			j;

	i = 0;
	while (paths[i].length)
	{
		j = -1;
		while (++j < paths[i].length)
			free(paths[i].nodes[j]);
		free(paths[i].nodes);
		i++;
	}
	free(paths);
}
