/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:45:42 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/09 23:30:11 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *str1, const char *str2, size_t len)
{
	char	*str1begin;
	size_t	str2len;

	str2len = ft_strlen(str2);
	str1begin = str1;
	while (*str1)
		str1++;
	ft_strncpy(str1, str2, len > str2len ? str2len : len);
	str1[len > str2len ? str2len : len] = 0;
	return (str1begin);
}
