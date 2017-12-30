/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:18:09 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/10 11:27:35 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(const char *str, unsigned int start, size_t len)
{
	char	*sub;

	if (!str)
		return (NULL);
	if (!(sub = ft_strnew(len)))
		return (NULL);
	ft_strncpy(sub, str + start, len);
	return (sub);
}
