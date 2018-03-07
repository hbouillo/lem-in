/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoabase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:20:52 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/29 15:15:46 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ulonglonglen(unsigned long long nbr, int base_n)
{
	size_t		len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= (unsigned long long)base_n;
		len++;
	}
	return (len);
}

char			*ft_ulltoabase(unsigned long long nbr, const char *base)
{
	char		*str;
	size_t		len;
	int			base_n;

	base_n = (int)ft_strlen(base);
	len = ulonglonglen(nbr, base_n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = base[(nbr % base_n)];
			nbr /= (unsigned long long)base_n;
		}
	}
	return (str);
}

void			ft_ulltoabase_buf(unsigned long long nbr,
					const char *base, char *str)
{
	size_t		len;
	int			base_n;

	base_n = (int)ft_strlen(base);
	len = ulonglonglen(nbr, base_n);
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = base[(nbr % base_n)];
			nbr /= (unsigned long long)base_n;
		}
	}
}
