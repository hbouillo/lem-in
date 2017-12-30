/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:13:05 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/10 11:27:02 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(const char *str1, const char *str2)
{
	if (!str1 && !str2)
		return (1);
	if (!str1 || !str2)
		return (0);
	return (ft_strcmp(str1, str2) == 0 ? 1 : 0);
}
