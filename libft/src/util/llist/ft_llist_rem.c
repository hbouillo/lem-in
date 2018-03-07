/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_rem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 01:22:25 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/03 07:04:08 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_llist_rem(t_llist **head, t_llist *elem,
						void (*del_data)(void *))
{
	t_llist			*tmp;

	if (!head)
		return ;
	tmp = *head;
	if (*head == elem)
	{
		*head = elem->next;
		if (del_data)
			del_data(elem->data);
		free(elem);
	}
	else
		while (tmp->next)
		{
			if (tmp->next == elem)
			{
				tmp->next = elem->next;
				if (del_data)
					del_data(elem->data);
				free(elem);
				return ;
			}
			tmp = tmp->next;
		}
}
