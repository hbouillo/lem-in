/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:19:28 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/10 11:30:13 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	const char		*bgin;
	size_t			tflen;

	if (!*to_find)
		return ((char *)str);
	tflen = ft_strlen(to_find);
	bgin = str - 1;
	while ((bgin = ft_strchr(++bgin, (int)*to_find))
		&& (bgin - str) <= ((long)len) - ((long)tflen))
		if (!ft_strncmp(bgin, to_find, tflen))
			return ((char *)bgin);
	return (NULL);
}
