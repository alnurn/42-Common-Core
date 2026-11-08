/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:29:22 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/28 11:29:24 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_closeprogram(t_data	*param)
{
	if (!param)
		return (1);
	ft_freemap(param->array);
	if (param->img)
		mlx_destroy_image(param->mlx, param->img);
	if (param->win)
		mlx_destroy_window(param->mlx, param->win);
	if (param->mlx)
	{
		mlx_destroy_display(param->mlx);
		free(param->mlx);
	}
	return (0);
}

size_t	ft_count_y(char	**array)
{
	size_t	i;

	i = 0;
	if (!array)
		return (i);
	while (array[i])
		i++;
	return (i);
}

size_t	ft_count_x(char	*str)
{
	size_t	i;
	size_t	count;
	int		flag;

	i = 0;
	flag = 0;
	count = 0;
	if (!str)
		return (count);
	while (str[i])
	{
		if (!flag && str[i] != ' ')
		{
			flag = 1;
			count++;
		}
		else if (str[i] == ' ')
			flag = 0;
		i++;
	}
	return (count);
}
