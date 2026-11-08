/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 19:43:18 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/28 19:43:22 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mouse_press_extra(int button, int x, int y, t_data	*param)
{
	if (button == KeyPress)
	{
		param->drag = 1;
		param->last_x = x;
		param->last_y = y;
	}
	else if (button == KeyRelease && !param->view_type)
	{
		param->rot = 1;
		param->last_rot_x = x;
		param->last_rot_y = y;
	}
}

int	mouse_press(int button, int x, int y, t_data	*param)
{
	if (!param)
		return (1);
	if (button == ButtonPress)
	{
		ft_memset(param->addr, 0, WIN_HEIGHT * param->line_len);
		param->zoom += 1;
		if (!param->zoom || param->zoom < 0)
			param->zoom = 1;
		ft_render(param);
	}
	else if (button == ButtonRelease)
	{
		ft_memset(param->addr, 0, WIN_HEIGHT * param->line_len);
		param->zoom -= 1;
		if (!param->zoom || param->zoom < 0)
			param->zoom = 1;
		ft_render(param);
	}
	mouse_press_extra(button, x, y, param);
	return (0);
}

static void	mouse_drag_extra(int x, int y, t_data	*param)
{
	int		delta_x;
	int		delta_y;
	float	sensitivity;
	float	rot_limit;

	if (param->rot && !param->view_type)
	{
		sensitivity = 0.005;
		rot_limit = 1.55;
		delta_x = x - param->last_rot_x;
		delta_y = y - param->last_rot_y;
		param->alpha += delta_y * sensitivity;
		param->tetha += delta_x * sensitivity;
		if (param->alpha > rot_limit)
			param->alpha = rot_limit;
		if (param->alpha < -rot_limit)
			param->alpha = -rot_limit;
		param->last_rot_x = x;
		param->last_rot_y = y;
		ft_memset(param->addr, 0, WIN_HEIGHT * param->line_len);
		ft_render(param);
	}
}

int	mouse_drag(int x, int y, t_data	*param)
{
	int	delta_x;
	int	delta_y;

	if (!param)
		return (0);
	if (param->drag)
	{
		delta_x = x - param->last_x;
		delta_y = y - param->last_y;
		param->shift_x += delta_x;
		param->shift_y += delta_y;
		param->last_x = x;
		param->last_y = y;
		ft_memset(param->addr, 0, WIN_HEIGHT * param->line_len);
		ft_render(param);
	}
	mouse_drag_extra(x, y, param);
	return (1);
}
