/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memadr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:55:41 by hbouillo          #+#    #+#             */
/*   Updated: 2017/11/23 00:29:25 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_memadr(const void *mem)
{
	char	*adr;

	adr = ft_strnew(14);
	ft_strcpy(adr, "0x");
	ft_strcpy(adr + 2, ft_ultoabase((unsigned long)mem, BASE_HEX));
	return (adr);
}
