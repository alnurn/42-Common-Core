/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 14:14:43 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/14 14:14:45 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_couplepix	ft_transform(t_point begin, t_point end, t_data *param)
{
	t_couplepix	pix;
	t_pix		pix_begin;
	t_pix		pix_end;

	ft_zoom(&begin, param);
	ft_rotate(&begin, param);
	pix_begin = param->projection(begin);
	ft_centralize(&pix_begin, param);
	ft_zoom(&end, param);
	ft_rotate(&end, param);
	pix_end = param->projection(end);
	ft_centralize(&pix_end, param);
	pix.begin = pix_begin;
	pix.end = pix_end;
	pix.start_color = begin.color;
	pix.end_color = end.color;
	return (pix);
}

void	ft_naming(t_data *param)
{
	if (param->proj_type == ISO)
		mlx_string_put(param->mlx, param->win, 10, 20, WHITE, "Isometric");
	else if (param->proj_type == ORTHO && !param->view_type)
		mlx_string_put(param->mlx, param->win, 10, 20, WHITE, "Orthographic");
	else if (param->proj_type == ORTHO && param->view_type == 1)
		mlx_string_put(param->mlx, param->win,
			10, 20, WHITE, "Orthographic / Top view");
	else if (param->proj_type == ORTHO && param->view_type == 2)
		mlx_string_put(param->mlx, param->win,
			10, 20, WHITE, "Orthographic / Front view");
	else if (param->proj_type == ORTHO && param->view_type == 3)
		mlx_string_put(param->mlx, param->win,
			10, 20, WHITE, "Orthographic / Right view");
	else if (param->proj_type == PERSPECTIVE && !param->view_type)
		mlx_string_put(param->mlx, param->win, 10, 20, WHITE, "Perspective");
	else if (param->proj_type == PERSPECTIVE && param->view_type == 1)
		mlx_string_put(param->mlx, param->win,
			10, 20, WHITE, "Perspective / Top");
	else if (param->proj_type == PERSPECTIVE && param->view_type == 2)
		mlx_string_put(param->mlx, param->win,
			10, 20, WHITE, "Perspective / Front");
	else if (param->proj_type == PERSPECTIVE && param->view_type == 3)
		mlx_string_put(param->mlx, param->win,
			10, 20, WHITE, "Perspective / Right");
}

void	ft_render_helper(t_data *param, size_t row)
{
	t_couplepix	couple_1;
	t_couplepix	couple_2;
	size_t		col;

	if (!param)
		return ;
	col = 0;
	while (col < param->size_x)
	{
		if (row < param->size_y - 1)
		{
			couple_1 = ft_transform(param->array[row][col],
					param->array[row + 1][col], param);
			ft_drawline(param, &couple_1);
		}
		if (col < param->size_x - 1)
		{
			couple_2 = ft_transform(param->array[row][col],
					param->array[row][col + 1], param);
			ft_drawline(param, &couple_2);
		}
		col++;
	}
}

int	ft_render(t_data *param)
{
	size_t		row;

	if (!param)
		ft_error(1);
	row = 0;
	while (row < param->size_y)
	{
		ft_render_helper(param, row);
		row++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	ft_naming(param);
	return (0);
}

void	ft_initmlx(t_data	*param)
{
	if (!param)
		ft_error(0);
	param->mlx = mlx_init();
	if (!param->mlx)
		ft_end(param->array, 4);
	param->img = mlx_new_image(param->mlx, WIN_WIDTH, WIN_HEIGHT);
	param->addr = mlx_get_data_addr(param->img, &param->bpp,
			&param->line_len, &param->endian);
	param->win = mlx_new_window(param->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (!param->win)
		ft_end(param->array, 4);
	ft_render(param);
	mlx_hook(param->win, DestroyNotify, 0, mouse_destroy, param);
	mlx_hook(param->win, KeyPress, 1L << 0, key_press, param);
	mlx_hook(param->win, ButtonPress, 1L << 2, mouse_press, param);
	mlx_hook(param->win, ButtonRelease, 1L << 3, mouse_release, param);
	mlx_hook(param->win, MotionNotify, 1L << 6, mouse_drag, param);
	mlx_hook(param->win, Expose, 1L << 15, ft_render, param);
	mlx_loop(param->mlx);
}
