/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:52:08 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/14 14:52:09 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_setview(t_data	*param, float alpha, float tetha, int view)
{
	ft_memset(param->addr, 0, WIN_HEIGHT * param->line_len);
	param->zoom = ZOOM_FACTOR;
	param->alpha = alpha;
	param->tetha = tetha;
	param->gamma = 0;
	param->shift_x = 0;
	param->shift_y = 0;
	param->view_type = view;
	ft_render(param);
}

static void	ft_offiso(t_data	*param)
{
	if (param->projection == ft_isometric)
	{
		param->proj_type = ORTHO;
		param->projection = ft_orthographic;
	}
}

static void	key_extra(int key, t_data	*param)
{
	if (key == XK_1)
	{
		ft_offiso(param);
		ft_setview(param, 0, 0, 1);
	}
	else if (key == XK_2)
	{
		ft_offiso(param);
		ft_setview(param, 1.57, 0, 2);
	}
	else if (key == XK_3)
	{
		ft_offiso(param);
		ft_setview(param, 1.57, 1.57, 3);
	}
}

int	key_press(int key, t_data	*param)
{
	if (!param)
		return (1);
	if (key == XK_Escape && !ft_closeprogram(param))
		exit (EXIT_SUCCESS);
	if (key == XK_p || key == XK_P)
	{
		param->projection = ft_perspective;
		param->proj_type = PERSPECTIVE;
		ft_setview(param, 3.14, 0, 0);
	}
	else if (key == XK_i || key == XK_I)
	{
		param->projection = ft_isometric;
		param->proj_type = ISO;
		ft_setview(param, 0, 0, 0);
	}
	else if (key == XK_o || key == XK_O)
	{
		param->projection = ft_orthographic;
		param->proj_type = ORTHO;
		ft_setview(param, 0.785, 0.785, 0);
	}
	key_extra(key, param);
	return (0);
}
