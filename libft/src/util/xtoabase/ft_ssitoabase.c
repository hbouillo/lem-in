/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssitoabase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 22:40:48 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/29 15:16:03 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ssizelen(ssize_t nbr, int base_n)
{
	size_t		len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= (ssize_t)base_n;
		len++;
	}
	return (len);
}

char			*ft_ssitoabase(ssize_t nbr, const char *base)
{
	char		*str;
	size_t		len;
	int			sign;
	int			base_n;

	base_n = (int)ft_strlen(base);
	sign = nbr < 0 ? 1 : 0;
	len = ssizelen(nbr, base_n) + sign;
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = base[(nbr % base_n) * (sign ? -1 : 1)];
			nbr /= (ssize_t)base_n;
		}
		if (sign)
			str[--len] = '-';
	}
	return (str);
}

void			ft_ssitoabase_buf(ssize_t nbr, const char *base, char *str)
{
	size_t		len;
	int			sign;
	int			base_n;

	base_n = (int)ft_strlen(base);
	sign = nbr < 0 ? 1 : 0;
	len = ssizelen(nbr, base_n) + sign;
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = base[(nbr % base_n) * (sign ? -1 : 1)];
			nbr /= (ssize_t)base_n;
		}
		if (sign)
			str[--len] = '-';
	}
}
