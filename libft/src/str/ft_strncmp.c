/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:50:02 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/08 14:12:40 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	min;

	min = ft_strlen(str1) + 1;
	min = min > ft_strlen(str2) + 1 ? ft_strlen(str2) + 1 : min;
	min = min > n ? n : min;
	return (ft_memcmp(str1, str2, min));
}
