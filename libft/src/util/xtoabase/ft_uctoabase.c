/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uctoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 22:40:48 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/29 15:21:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ucharlen(unsigned char nbr, int base_n)
{
	size_t		len;

	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= (unsigned char)base_n;
		len++;
	}
	return (len);
}

char			*ft_uctoabase(unsigned char nbr, const char *base)
{
	char		*str;
	size_t		len;
	int			base_n;

	base_n = (int)ft_strlen(base);
	len = ucharlen(nbr, base_n);
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
			nbr /= (unsigned char)base_n;
		}
	}
	return (str);
}

void			ft_uctoabase_buf(unsigned char nbr,
					const char *base, char *str)
{
	size_t		len;
	int			base_n;

	base_n = (int)ft_strlen(base);
	len = ucharlen(nbr, base_n);
	str[len] = 0;
	if (!nbr)
		str[0] = '0';
	else
	{
		while (nbr)
		{
			str[--len] = base[(nbr % base_n)];
			nbr /= (unsigned char)base_n;
		}
	}
}
