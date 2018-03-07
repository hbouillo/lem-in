/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:56:38 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/10 11:25:02 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapif(const char *str, const void *data,
								int (*f_condition)(char, const void *),
								char (*f)(char))
{
	char			*fstr;
	unsigned int	idx;

	if (!str || !f || !f_condition)
		return (NULL);
	idx = -1;
	if (!(fstr = ft_strdup(str)))
		return (NULL);
	while (str[++idx])
		if (f_condition(str[idx], data))
			fstr[idx] = f(str[idx]);
	return (fstr);
}
