/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:18:34 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/07 15:26:19 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *to_fill, int value, size_t len)
{
	size_t counter;

	counter = -1;
	while (++counter < len)
		((unsigned char *)to_fill)[counter] = (unsigned char)value;
	return (to_fill);
}
