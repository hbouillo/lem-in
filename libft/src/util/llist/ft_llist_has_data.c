/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_has_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 04:40:06 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 04:41:03 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_llist_has_data(t_llist *list, void *data)
{
	while (list)
	{
		if (list->data == data)
			return (1);
		list = list->next;
	}
	return (0);
}
