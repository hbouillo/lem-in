/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 05:46:43 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/07 06:00:55 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"

static void			init_data_tubes(t_data *data)
{
	if (!(data->id_tubes_count = (int *)ft_memalloc(
			sizeof(int) * data->rooms_count)) ||
		!(data->id_tubes = (int **)ft_memalloc(
			sizeof(int *) * data->rooms_count)))
		error(ERR_MALLOC, ERR_CRITICAL);
}

static void			link_rooms_id(t_data *data, t_llist *tubes)
{
	t_tube			*tube;
	int				i;

	while (tubes)
	{
		tube = (t_tube *)tubes->data;
		i = 0;
		while (data->id_tubes[tube->room1->id][i] &&
				i < data->id_tubes_count[tube->room1->id])
			i++;
		data->id_tubes[tube->room1->id][i] = tube->room2->id;
		i = 0;
		while (data->id_tubes[tube->room2->id][i] &&
				i < data->id_tubes_count[tube->room2->id])
			i++;
		data->id_tubes[tube->room2->id][i] = tube->room1->id;
		tubes = tubes->next;
	}
}

void				process_data(t_data *data, t_llist *tubes)
{
	t_tube			*tube;
	t_llist			*tubes_save;
	int				room;

	init_data_tubes(data);
	tubes_save = tubes;
	while (tubes)
	{
		tube = (t_tube *)tubes->data;
		data->id_tubes_count[tube->room1->id]++;
		data->id_tubes_count[tube->room2->id]++;
		tubes = tubes->next;
	}
	room = -1;
	while (++room < data->rooms_count)
		if (!(data->id_tubes[room] = (int *)ft_memalloc(
				sizeof(int) * data->id_tubes_count[room])))
			error(ERR_MALLOC, ERR_CRITICAL);
	link_rooms_id(data, tubes_save);
}

int					fill_connections(t_node *node, t_node **list_nodes,
						t_data *data)
{
	int				i;

	i = -1;
	while (++i < node->connections)
		node->nodes[i] = list_nodes[data->id_tubes[node->id][i]];
	return (0);
}

void				remove_double_links(t_node *node)
{
	int				i;
	int				j;

	i = -1;
	while (++i < node->connections)
	{
		j = -1;
		while (++j < node->connections)
		{
			if ((node->nodes[i] && i != j &&
				node->nodes[i] == node->nodes[j]))
			{
				error(ERR_TUBE_ALREADY_EXISTS, ERR_WARNING);
				node->nodes[i] = NULL;
			}
		}
	}
}
