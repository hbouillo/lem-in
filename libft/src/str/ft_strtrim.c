/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:25:22 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/10 11:29:08 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *str)
{
	int		start;
	int		end;

	if (!str)
		return (NULL);
	start = 0;
	end = ft_strlen(str);
	while (ft_strchr(" \t\n", (int)str[start]))
		start++;
	while (ft_strchr(" \t\n", (int)str[end - 1]))
		end--;
	if (end < start)
		return (ft_strnew(0));
	return (ft_strsub(str, start, end - start));
}
