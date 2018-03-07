/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:55:47 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/07 04:46:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./args.h"

static void			destroy_inst_args(t_arg *arg)
{
	if (!arg)
		return ;
	destroy_inst_args(arg->next);
	ft_chartabfree(arg->data);
	free(arg);
}

static void			destroy_ref_args(t_refarg *refarg)
{
	if (!refarg)
		return ;
	destroy_ref_args(refarg->next);
	free(refarg->name);
	free(refarg);
}

void				destroy_args(void)
{
	t_args			**args;

	args = get_args();
	destroy_inst_args((*args)->args);
	destroy_ref_args((*args)->ref_args);
	free(*args);
	*args = NULL;
}
