/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:38:34 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/14 13:38:35 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_readfile(int fd)
{
	char	*str;
	char	*temp;

	temp = NULL;
	str = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		str = ft_strjoin(str, temp);
	}
	return (str);
}

int	ft_checkmap(char	**array)
{
	size_t	x;
	size_t	x_temp;
	size_t	y_temp;
	size_t	i;

	if (!array)
		return (0);
	x_temp = ft_count_x(array[0]);
	y_temp = ft_count_y(array);
	if (!x_temp || !y_temp)
		return (0);
	i = 1;
	while (array[i])
	{
		x = ft_count_x(array[i]);
		if (x_temp != x)
			return (0);
		i++;
	}
	return (1);
}

void	ft_fillmap(t_data	*param, char	**array, size_t row)
{
	size_t	col;
	char	**sub_arr;

	param->array[row] = (t_point *) malloc(param->size_x * sizeof(t_point));
	if (!param->array[row])
	{
		ft_freearray(array);
		ft_end(param->array, 0);
	}
	col = 0;
	sub_arr = ft_split(array[row], ' ');
	while (sub_arr[col])
	{
		param->array[row][col].z = ft_atoi(sub_arr[col]);
		param->array[row][col].y = row - param->size_y / 2;
		param->array[row][col].x = col - param->size_x / 2;
		param->array[row][col].color = ft_setcolor(sub_arr[col]);
		col++;
	}
	ft_freearray(sub_arr);
}

void	ft_initmap(t_data	*param, char	**array)
{
	size_t	row;

	if (!param)
	{
		ft_freearray(array);
		ft_error(0);
	}
	param->size_x = ft_count_x(array[0]);
	param->size_y = ft_count_y(array);
	param->array = (t_point **) malloc((param->size_y + 1) * sizeof(t_point *));
	if (!param->array)
	{
		ft_freearray(array);
		ft_error(4);
	}
	row = 0;
	while (row < param->size_y)
	{
		ft_fillmap(param, array, row);
		row++;
	}
	param->array[param->size_y] = NULL;
}
