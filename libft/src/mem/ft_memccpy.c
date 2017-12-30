/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:54:34 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/07 16:36:34 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src,
								int value, size_t len)
{
	unsigned char	*ucdst;
	unsigned char	*ucsrc;

	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	while (len-- > 0)
	{
		*(ucdst++) = *(ucsrc++);
		if (*(ucdst - 1) == (unsigned char)value)
			return ((void *)ucdst);
	}
	return (NULL);
}
