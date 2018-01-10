/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 05:06:17 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/10 05:11:28 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./args.h"

t_arg		*get_arg(int idx)
{
	t_arg	*arg;

	arg = (*get_args())->args;
	while (arg)
	{
		if (arg->idx == idx)
			return (arg);
		arg = arg->next;
	}
	return (NULL);
}
