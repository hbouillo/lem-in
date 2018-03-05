/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 00:04:19 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/05 00:09:33 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

long			djb2(char const *str)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
	    hash = ((hash << 5) + hash) + c;
	return (hash);
}
