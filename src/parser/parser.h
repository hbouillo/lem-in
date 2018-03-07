/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 03:07:33 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/07 05:49:09 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "lemin.h"

int					parse_room(char **split, t_data *data, t_cdata *cdata);
int					parse_tube(char **split, t_data *data, t_cdata *cdata);

t_room				*find_room(char *name, t_data *data);

void				process_data(t_data *data, t_llist *tubes);
int					fill_connections(t_node *node, t_node **list_nodes,
						t_data *data);
void				remove_double_links(t_node *node);
#endif
