/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:04:53 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/14 15:05:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_maketrgb(int start_color, int end_color, int t)
{
	t_trgb	trgb_1;
	t_trgb	trgb_2;
	t_trgb	trgb;

	trgb_1.t = get_transparent(start_color);
	trgb_1.r = get_red(start_color);
	trgb_1.g = get_green(start_color);
	trgb_1.b = get_blue(start_color);
	trgb_2.t = get_transparent(end_color);
	trgb_2.r = get_red(end_color);
	trgb_2.g = get_green(end_color);
	trgb_2.b = get_blue(end_color);
	trgb.t = trgb_1.t + (trgb_2.t - trgb_1.t) * t / 1000;
	trgb.r = trgb_1.r + (trgb_2.r - trgb_1.r) * t / 1000;
	trgb.g = trgb_1.g + (trgb_2.g - trgb_1.g) * t / 1000;
	trgb.b = trgb_1.b + (trgb_2.b - trgb_1.b) * t / 1000;
	return (trgb.t << 24 | trgb.r << 16 | trgb.g << 8 | trgb.b);
}

int	ft_createcolor(t_pix	*current, t_couplepix	*couple, t_delta	*d)
{
	int	color;
	int	t;

	if (!current || !couple || !d)
		return (0);
	t = 0;
	if (d->absdx > d->absdy)
	{
		if (couple->end.x - couple->begin.x)
			t = (current->x - couple->begin.x) * 1000
				/ (couple->end.x - couple->begin.x);
	}
	else
	{
		if (couple->end.y - couple->begin.y)
			t = (current->y - couple->begin.y) * 1000
				/ (couple->end.y - couple->begin.y);
	}
	color = ft_maketrgb(couple->start_color, couple->end_color, t);
	return (color);
}

int	ft_setcolor(char	*str)
{
	size_t	i;

	if (!str)
		return (0xFFA500);
	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == '0'
			&& (str[i + 2] == 'x' || str[i + 2] == 'X'))
			return (ft_atoi_base(&str[i + 3], 16));
		i++;
	}
	return (0xFFA500);
}
