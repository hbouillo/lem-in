/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:45:09 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/10 11:24:09 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *str, void (*f)(unsigned int, char *))
{
	unsigned int	idx;

	if (!str || !f)
		return ;
	idx = -1;
	while (str[++idx])
		f(idx, str + idx);
}
