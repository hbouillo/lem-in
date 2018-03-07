/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_m_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:27:52 by hbouillo          #+#    #+#             */
/*   Updated: 2017/12/04 21:55:09 by hbouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				handle_m_u(va_list *arg, t_convseq *convseq, char **buf)
{
	convseq->conv = u;
	convseq->len = l;
	return (handle_u(arg, convseq, buf));
}
