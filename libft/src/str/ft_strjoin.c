/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:22:03 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/10 11:28:34 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(const char *str1, const char *str2)
{
	char	*join;

	if (!str1 || !str2)
		return (NULL);
	if (!(join = ft_strnew(ft_strlen(str1) + ft_strlen(str2))))
		return (NULL);
	ft_strcpy(join, str1);
	ft_strcat(join, str2);
	return (join);
}
