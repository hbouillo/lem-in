/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:45:58 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/09 23:29:45 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *mem1, const void *mem2,
								size_t len)
{
	const unsigned char	*cmem1;
	const unsigned char	*cmem2;

	cmem1 = (const unsigned char *)mem1;
	cmem2 = (const unsigned char *)mem2;
	while (len-- > 0)
		if (*(cmem1++) != *(cmem2++))
			return (*(cmem1 - 1) - *(cmem2 - 1));
	return (0);
}
