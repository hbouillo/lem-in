/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 19:54:43 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:53:55 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int						apply_conv(va_list *arg, t_convseq *convseq, char **buf)
{
	static int	(*const handlers[17])(va_list *, t_convseq *, char **buf) =
	{ &handle_s, &handle_m_s, &handle_p, &handle_d, &handle_d, &handle_m_d,
	&handle_o, &handle_m_o, &handle_u, &handle_m_u, &handle_x, &handle_m_x,
	&handle_c, &handle_m_c, &handle_percent, &handle_b, &handle_rgb };

	handlers[convseq->conv - 1](arg, convseq, buf);
	return (0);
}
