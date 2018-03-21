/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 19:24:35 by hbouillo          #+#    #+#             */
/*   Updated: 2018/03/21 17:25:23 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				error(int errcode, char const *const errmsg, char *errtype,
						int errexit)
{
	if (get_arg(ARG_VERBOSE))
	{
		ft_printf("%rgb%s (ERRCODE=%d, ERRMSG=\"%s\")%0rgb\n",
			errexit ? 0xff3835 : 0xf7ba2c, errtype, errcode, errmsg);
		if (errexit)
			exit(1);
	}
	else if (errexit)
	{
		ft_printf("ERROR\n");
		exit(1);
	}
	return (1);
}

void			check_data(t_data *data)
{
	if (!data->start)
		error(ERR_NO_START_NODE, ERR_CRITICAL);
	else if (!data->end)
		error(ERR_NO_END_NODE, ERR_CRITICAL);
}

void			lemin(int max_paths, int max_length)
{
	t_data		*data;
	t_network	*network;
	t_path		*paths;
	int			ants;

	sverbose("%rgbParsing...\n%0rgb", V_COLOR);
	data = parse_data();
	ants = data->ants;
	sverbose("%rgbDone.\n%rgbChecking data...\n%0rgb", V_COLOR, V_COLOR);
	check_data(data);
	sverbose("%rgbDone.\n%rgbBuilding network...\n%0rgb", V_COLOR, V_COLOR);
	network = build_network(data);
	sverbose("%rgbDone.\n%0rgb", V_COLOR);
	free_data(data);
	verbose("%d nodes detected in network. Node Name(%s) is entry. \
Node Name(%s) is exit.\n", network->nodes_count, network->entry->name,
		network->exit->name);
	sverbose("%rgbSolving...\n%0rgb", V_COLOR);
	paths = solve(network, max_paths, max_length);
	sverbose("%rgbDone.\n%0rgb", V_COLOR);
	free_network(network);
	run_ants(ants, paths);
	free_paths(paths);
}

static int		usage(void)
{
	ft_putstr("Usage: lem-in [--verbose] [--print] [--max-paths n] \
[--max-path-length l]\n");
	ft_putstr("\t--print (-p): Starts lem-in in print mode. \
Shows only major steps.\n");
	ft_putstr("\t--verbose (-v): Starts lem-in in verbose mode. \
Shows every step lem-in does.\n");
	ft_putstr("\t--max-paths n (-n n): Lem-in won't search more than n paths. \
By default, no limit is set.\n");
	ft_putstr("\t--max-path-length l (-l l): Lem-in won't search paths longer \
than l nodes. By default, no limit is set.\n");
	return (1);
}

int				main(int argc, char **argv)
{
	int			max_paths;
	int			max_length;

	max_paths = 0;
	max_length = 0;
	register_arg_ref("verbose", 'v', 0, ARG_VERBOSE);
	register_arg_ref("print", 'p', 0, ARG_PRINT);
	register_arg_ref("max-paths", 'n', 1, ARG_MAX_PATHS);
	register_arg_ref("max-path-length", 'l', 1, ARG_MAX_LENGTH);
	if (parse_args(argc, argv))
		return (usage());
	if (get_arg(ARG_MAX_PATHS))
		max_paths = ft_nbrmax(ft_atoi(get_arg(ARG_MAX_PATHS)->data[0]), 0);
	if (get_arg(ARG_MAX_LENGTH))
		max_length = ft_nbrmax(ft_atoi(get_arg(ARG_MAX_LENGTH)->data[0]), 1);
	lemin(max_paths, max_length);
	destroy_args();
	return (0);
}
