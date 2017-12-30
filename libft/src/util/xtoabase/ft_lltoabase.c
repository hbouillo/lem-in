/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:20:52 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/29 15:16:15 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	longlonglen(long long nbr, int base_n)
{
	size_t		len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= (long long)base_n;
		len++;
	}
	return (len);
}

char			*ft_lltoabase(long long nbr, const char *base)
{
	char		*str;
	size_t		len;
	int			sign;
	int			base_n;

	base_n = (int)ft_strlen(base);
	sign = nbr < 0 ? 1 : 0;
	len = longlonglen(nbr, base_n) + sign;
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
			nbr /= (long long)base_n;
		}
		if (sign)
			str[--len] = '-';
	}
	return (str);
}

void			ft_lltoabase_buf(long long nbr, const char *base, char *str)
{
	size_t		len;
	int			sign;
	int			base_n;

	base_n = (int)ft_strlen(base);
	sign = nbr < 0 ? 1 : 0;
	len = longlonglen(nbr, base_n) + sign;
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = base[(nbr % base_n) * (sign ? -1 : 1)];
			nbr /= (long long)base_n;
		}
		if (sign)
			str[--len] = '-';
	}
}
