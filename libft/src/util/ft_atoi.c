/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:40:54 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/24 16:07:03 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		nbr;
	int		sign;

	while (*str && ft_strchr(" \n\v\t\r\f", *str))
		str++;
	sign = *str == '-' ? -1 : 1;
	if (*str && ft_strchr("+-", *str))
		str++;
	nbr = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			break ;
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (nbr * sign);
}
