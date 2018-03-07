/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:22:11 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/29 15:15:43 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ulonglen(unsigned long nbr, int base_n)
{
	size_t		len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= (unsigned long)base_n;
		len++;
	}
	return (len);
}

char			*ft_ultoabase(unsigned long nbr, const char *base)
{
	char		*str;
	size_t		len;
	int			base_n;

	base_n = (int)ft_strlen(base);
	len = ulonglen(nbr, base_n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = base[nbr % base_n];
			nbr /= (unsigned long)base_n;
		}
	}
	return (str);
}

void			ft_ultoabase_buf(unsigned long nbr,
					const char *base, char *str)
{
	size_t		len;
	int			base_n;

	base_n = (int)ft_strlen(base);
	len = ulonglen(nbr, base_n);
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = base[nbr % base_n];
			nbr /= (unsigned long)base_n;
		}
	}
}
