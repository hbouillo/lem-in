/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:15:53 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/10 11:27:17 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(const char *str1, const char *str2, size_t len)
{
	if (!str1 && !str2)
		return (1);
	if (!str1 || !str2)
		return (0);
	return (ft_strncmp(str1, str2, len) == 0 ? 1 : 0);
}
