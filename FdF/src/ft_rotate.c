/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:14:43 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/14 14:14:45 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_z(t_point	*point, float gamma)
{
	int	tmp;

	tmp = point->x;
	point->x = tmp * cos(gamma) - point->y * sin(gamma);
	point->y = tmp * sin(gamma) + point->y * cos(gamma);
}

void	ft_rotate_y(t_point	*point, float tetha)
{
	int	tmp;

	tmp = point->x;
	point->x = tmp * cos(tetha) + point->z * sin(tetha);
	point->z = point->z * cos(tetha) - tmp * sin(tetha);
}

void	ft_rotate_x(t_point	*point, float alpha)
{
	int	tmp;

	tmp = point->y;
	point->y = tmp * cos(alpha) - point->z * sin(alpha);
	point->z = tmp * sin(alpha) + point->z * cos(alpha);
}

void	ft_rotate(t_point	*point, t_data *param)
{
	if (!param)
		ft_error(0);
	if (!point)
		ft_end(param->array, 4);
	ft_rotate_x(point, param->alpha);
	ft_rotate_y(point, param->tetha);
	ft_rotate_z(point, param->gamma);
}
