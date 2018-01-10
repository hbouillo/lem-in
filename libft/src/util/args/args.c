/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:44:26 by hbouillo          #+#    #+#             */
/*   Updated: 2018/01/10 05:13:10 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./args.h"

t_args				**get_args()
{
	static t_args	*args;

	if (!args)
		args = (t_args *)ft_memalloc(sizeof(t_args));
	return (&args);
}

void				register_arg_ref(char *name, char short_name,
						int data_len, int idx)
{
	t_args			**args;
	t_refarg		*refarg;
	t_refarg		*tmp;

	refarg = (t_refarg *)ft_memalloc(sizeof(t_refarg));
	refarg->idx = idx;
	refarg->name = ft_strdup(name);
	refarg->short_name = short_name;
	refarg->data_len = data_len;
	args = get_args();
	if (!(*args)->ref_args)
		(*args)->ref_args = refarg;
	else
	{
		tmp = (*args)->ref_args;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = refarg;
	}
}

static t_refarg		*find_refarg(char *name, int name_type)
{
	t_refarg		*refarg;
	int				found;

	found = 0;
	refarg = (*get_args())->ref_args;
	while (refarg)
	{
		if ((name_type == ARG_LONG_NAME && ft_strequ(name, refarg->name)) ||
			(name_type == ARG_SHORT_NAME && *name == refarg->short_name))
		{
			return (refarg);
		}
		refarg = refarg->next;
	}
	return (NULL);
}

int					parse_args(int argc, char **argv)
{
	int				i;
	int				j;
	t_refarg		*refarg;
	t_arg			*arg;
	t_arg			*tmp;

	i = 0;
	(*get_args())->args = (t_arg *)ft_memalloc(sizeof(t_arg));
	(*get_args())->args->idx = ARG_DEFAULT;
	(*get_args())->args->data = (char **)ft_memalloc(sizeof(char *) * 2);
	(*get_args())->args->data[0] = ft_strnew(0);
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			refarg = argv[i][1] == '-' ? find_refarg(argv[i] + 2, ARG_LONG_NAME)
				: find_refarg(argv[i] + 1, ARG_SHORT_NAME);
			if (!refarg || refarg->data_len + i >= argc)
				return (1);
			arg = (t_arg *)ft_memalloc(sizeof(t_arg));
			arg->idx = refarg->idx;
			arg->data = (char **)ft_memalloc(sizeof(char *) * (refarg->data_len + 1));
			j = -1;
			while (++j < (int)refarg->data_len)
				arg->data[j] = argv[i + j + 1];
			i += j;
			tmp = (*get_args())->args;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = arg;
		}
		else
		{
			if (ft_strlen((*get_args())->args->data[0]))
				(*get_args())->args->data[0] = ft_strfjoin((*get_args())->args->data[0], ft_strdup(" "));
			(*get_args())->args->data[0] = ft_strfjoin((*get_args())->args->data[0], ft_strdup(argv[i]));
		}
	}
	return(0);
}
