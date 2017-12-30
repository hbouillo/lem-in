/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:08:37 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/09 23:30:29 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *str, const char *to_find)
{
	const char	*bgin;
	int			tflen;

	if (!*to_find)
		return ((char *)str);
	tflen = ft_strlen(to_find);
	bgin = str - 1;
	while ((bgin = ft_strchr(++bgin, (int)*to_find)))
		if (!ft_strncmp(bgin, to_find, tflen))
			return ((char *)bgin);
	return (NULL);
}
