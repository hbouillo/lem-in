/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:48:38 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/10 11:24:36 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmap(const char *str, char (*f)(char))
{
	char			*fstr;
	unsigned int	idx;

	if (!str || !f)
		return (NULL);
	idx = -1;
	if (!(fstr = ft_strnew(ft_strlen(str))))
		return (NULL);
	while (str[++idx])
		fstr[idx] = f(str[idx]);
	return (fstr);
}
