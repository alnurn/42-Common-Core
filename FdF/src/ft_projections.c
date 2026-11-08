/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:14:43 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/14 14:14:45 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pix	ft_orthographic(t_point point)
{
	t_pix	pix;

	pix.x = point.x;
	pix.y = point.y;
	return (pix);
}

t_pix	ft_isometric(t_point point)
{
	t_pix	pix;
	int		tmp;

	tmp = point.x;
	pix.x = (tmp - point.y) * cos(0.523599);
	pix.y = (tmp + point.y) * sin(0.523599) - point.z;
	return (pix);
}

t_pix	ft_perspective(t_point point)
{
	t_pix	pix;
	int		d;
	int		factor;

	d = 500;
	if (point.z + d)
		factor = d * 1000 / (point.z + d);
	else
		factor = d * 1000;
	pix.x = point.x * factor / 1000;
	pix.y = point.y * factor / 1000;
	return (pix);
}
