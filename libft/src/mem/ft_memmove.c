/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:19:47 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/09 15:26:02 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	if (src > dst)
		ft_memcpy(dst, src, len);
	else
	{
		cdst = ((char *)dst) + len - 1;
		csrc = ((char *)src) + len - 1;
		while (len-- > 0)
			*(cdst--) = *(csrc--);
	}
	return (dst);
}
