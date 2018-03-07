/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:55:28 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/09 23:18:39 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(int nbr)
{
	int			len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void			ft_putnbr_fd(int nbr, int fd)
{
	char		str[intlen(nbr) + (nbr < 0 ? 1 : 0)];
	size_t		len;
	int			sign;

	sign = nbr < 0 ? 1 : 0;
	len = intlen(nbr) + sign;
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = (nbr % 10) * (sign ? -1 : 1) + '0';
			nbr /= 10;
		}
		if (sign)
			str[--len] = '-';
	}
	ft_putstr_fd(str, fd);
}
