/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:49:48 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/01 19:30:44 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *str1, const char *str2, size_t size)
{
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 >= size)
		return (size + len2);
	str1 += len1;
	ft_strncpy(str1, str2, ft_nbrmin(len2, size - len1));
	str1[ft_nbrmin(len2, size - len1 - 1)] = 0;
	return (len1 + len2);
}
