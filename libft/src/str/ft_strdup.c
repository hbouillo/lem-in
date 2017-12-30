/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:54:31 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/09 22:45:07 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*dst;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!(dst = ft_strnew(srclen)))
		return (NULL);
	ft_memcpy(dst, src, srclen);
	return (dst);
}
