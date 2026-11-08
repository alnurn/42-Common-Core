/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:14:43 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/14 14:14:45 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_point	*point, t_data *param)
{
	if (!param)
		ft_error(0);
	if (!point)
		ft_end(param->array, 0);
	point->x *= param->zoom;
	point->y *= param->zoom;
	point->z *= param->zoom;
}

void	ft_centralize(t_pix	*pix, t_data *param)
{
	if (!param)
		ft_error(0);
	if (!pix)
		ft_end(param->array, 0);
	pix->x += WIN_WIDTH / 2 + param->shift_x;
	pix->y += WIN_HEIGHT / 2 + param->shift_y;
}
