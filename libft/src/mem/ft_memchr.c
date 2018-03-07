/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:24:26 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/07 17:06:26 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *to_search, int value, size_t len)
{
	const unsigned char	*ucts;

	ucts = (const unsigned char *)to_search;
	while (len-- > 0)
		if (*(ucts++) == (unsigned char)value)
			return ((void *)(--ucts));
	return (NULL);
}
