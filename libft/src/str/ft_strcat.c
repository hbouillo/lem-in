/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:40:39 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/07 17:44:41 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *str1, const char *str2)
{
	char	*str1begin;

	str1begin = str1;
	while (*str1)
		str1++;
	ft_strcpy(str1, str2);
	return (str1begin);
}
