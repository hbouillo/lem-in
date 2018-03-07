/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:22:29 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/08 12:08:32 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *str, int value)
{
	const char	*last;

	last = NULL;
	if (!((char)value))
		return ((char *)(str + ft_strlen(str)));
	while (*str)
		if (*(str++) == (char)value)
			last = str - 1;
	return ((char *)last);
}
