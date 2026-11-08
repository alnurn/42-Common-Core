/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_events_extra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:53:17 by anurmach          #+#    #+#             */
/*   Updated: 2026/03/01 15:53:21 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_destroy(t_data	*param)
{
	if (!param)
		return (1);
	if (!ft_closeprogram(param))
		exit (EXIT_SUCCESS);
	return (1);
}

int	mouse_release(int button, int x, int y, t_data	*param)
{
	(void) x;
	(void) y;
	if (!param)
		return (1);
	if (button == KeyPress)
		param->drag = 0;
	else if (button == KeyRelease && !param->view_type)
		param->rot = 0;
	return (0);
}
