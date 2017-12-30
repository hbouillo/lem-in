/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:24:35 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/30 19:59:38 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void			error(int exitcode)
{
	ft_putendl("ERROR");
	exit(exitcode);
}

int				main(int argc, char **argv)
{
	t_data		*data;

	data = parse_data();
	return (0);
}
