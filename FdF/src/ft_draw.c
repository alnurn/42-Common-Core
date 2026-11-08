/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:19:55 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/14 13:19:59 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_data	*param, t_pix	*current,
	t_couplepix	*couple, t_delta	*d)
{
	char	*addr;

	if (!param || !current || !couple || !d)
		return ;
	if (current->x < 0 || current->y < 0
		|| current->y >= WIN_HEIGHT || current->x >= WIN_WIDTH)
		return ;
	addr = param->addr + ((current->y * param->line_len)
			+ (current->x * (param->bpp / 8)));
	*(unsigned int *)addr = ft_createcolor(current, couple, d);
}

void	ft_drawx(t_data	*param, t_couplepix	*couple, t_delta	*d)
{
	t_pix	current;

	if (!param || !couple || !d)
		return ;
	current.y = couple->begin.y;
	current.x = couple->begin.x;
	while (1)
	{
		my_pixel_put(param, &current, couple, d);
		if (current.x == couple->end.x)
			break ;
		d->step += (int) d->absdy;
		if (d->step >= (int) d->absdx)
		{
			d->step -= (int) d->absdx;
			current.y += d->dir_y;
		}
		current.x += d->dir_x;
	}
}

void	ft_drawy(t_data	*param, t_couplepix	*couple, t_delta	*d)
{
	t_pix	current;

	if (!param || !couple || !d)
		return ;
	current.y = couple->begin.y;
	current.x = couple->begin.x;
	while (1)
	{
		my_pixel_put(param, &current, couple, d);
		if (current.y == couple->end.y)
			break ;
		d->step += (int) d->absdx;
		if (d->step >= (int) d->absdy)
		{
			d->step -= (int) d->absdy;
			current.x += d->dir_x;
		}
		current.y += d->dir_y;
	}
}

void	ft_drawline(t_data	*param, t_couplepix	*couple)
{
	t_delta	d;

	if (!param || !couple)
		return ;
	d.dx = couple->end.x - couple->begin.x;
	d.dy = couple->end.y - couple->begin.y;
	d.absdx = abs(d.dx);
	d.absdy = abs(d.dy);
	d.step = 0;
	d.dir_y = 0;
	d.dir_x = 0;
	if (d.dy > 0)
		d.dir_y = 1;
	else if (d.dy < 0)
		d.dir_y = -1;
	if (d.dx > 0)
		d.dir_x = 1;
	else if (d.dx < 0)
		d.dir_x = -1;
	if (d.absdx >= d.absdy)
		ft_drawx(param, couple, &d);
	else
		ft_drawy(param, couple, &d);
}
