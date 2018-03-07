/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 01:12:05 by hbouillo          #+#    #+#             */
/*   Updated: 2018/02/14 01:46:49 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llist				*ft_llist_new(void *data)
{
	t_llist			*new;

	if (!(new = ft_memalloc(sizeof(t_llist))))
		return (NULL);
	new->data = data;
	return (new);
}
