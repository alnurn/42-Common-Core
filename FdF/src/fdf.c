/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:18:29 by anurmach          #+#    #+#             */
/*   Updated: 2026/01/17 14:18:37 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init(t_data	*param)
{
	param->zoom = ZOOM_FACTOR;
	param->drag = 0;
	param->last_x = 0;
	param->last_y = 0;
	param->shift_x = 0;
	param->shift_y = 0;
	param->alpha = 0;
	param->tetha = 0;
	param->gamma = 0;
	param->proj_type = ISO;
	param->view_type = 0;
	param->projection = ft_isometric;
	param->rot = 0;
	param->last_rot_x = 0;
	param->last_rot_y = 0;
}

void	ft_start(char	*file)
{
	char	**array;
	t_data	param;

	if (!file)
		ft_error(0);
	array = ft_split(file, '\n');
	free(file);
	if (!ft_checkmap(array))
	{
		ft_freearray(array);
		ft_error(0);
	}
	ft_initmap(&param, array);
	ft_freearray(array);
	ft_init(&param);
	ft_initmlx(&param);
}

int	main(int argc, char	**argv)
{
	int		fd;
	char	*file;

	if (argc != 2)
		ft_error(1);
	fd = open((const char *) argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(2);
	file = ft_readfile(fd);
	fd = close(fd);
	if (fd < 0)
	{
		free(file);
		ft_error(3);
	}
	ft_start(file);
	return (EXIT_SUCCESS);
}
