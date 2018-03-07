/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:17:53 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/01 07:18:08 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isseparator(char c, const void *separator)
{
	return (c == *((char *)separator));
}

static char	zero(char c)
{
	c = 0;
	return (c);
}

static int	countwords(const char *str, const char *str0)
{
	int		words;

	words = -2;
	while (*str)
	{
		if (*str0 && (words == -2 || !str0[-1]))
			words++;
		if (words < 0)
			words += 2;
		str++;
		str0++;
	}
	return (words < 0 ? 0 : words);
}

char		**ft_strsplit(const char *str, char c)
{
	char	*str0;
	int		prev0;
	int		curr0;
	int		words;
	char	**tab;

	if (!(str0 = ft_strmapif(str, &c, &isseparator, &zero)))
		return (NULL);
	words = countwords(str, str0);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (words + 1))))
		return (NULL);
	prev0 = ft_strlen(str);
	while (words)
	{
		while (!str0[prev0 - 1])
			prev0--;
		curr0 = prev0;
		while (prev0 && str0[prev0 - 1])
			prev0--;
		if (!(tab[--words] = ft_strsub(str, prev0, curr0 - prev0)))
			return (NULL);
	}
	free(str0);
	return (tab);
}
