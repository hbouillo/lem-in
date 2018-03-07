/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:56:08 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/10 11:24:47 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*fstr;
	unsigned int	idx;

	if (!str || !f)
		return (NULL);
	idx = -1;
	if (!(fstr = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[++idx])
		fstr[idx] = f(idx, str[idx]);
	return (fstr);
}
