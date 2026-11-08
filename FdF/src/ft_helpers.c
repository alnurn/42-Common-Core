/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:38:34 by anurmach          #+#    #+#             */
/*   Updated: 2026/02/14 13:38:35 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_freearray(char	**array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_freemap(t_point	**array)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_error(int n)
{
	if (n == 1)
		ft_putstr_fd("WRONG NUMBER OF ARGUMENTS\n", STDERR_FILENO);
	else if (n == 2)
		ft_putstr_fd("FILE DOESN'T EXIST\n", STDERR_FILENO);
	else if (n == 3)
		ft_putstr_fd("ERROR WHILE CLOSING FILE\n", STDERR_FILENO);
	else if (n == 4)
		ft_putstr_fd("X SERVER CONNECTION FAILED\n", STDERR_FILENO);
	else if (n == 5)
		ft_putstr_fd("ERROR WHILE OPENING WINDOW", STDERR_FILENO);
	else
		ft_putstr_fd("ERROR\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_end(t_point	**array, int n)
{
	if (!array)
		ft_error(n);
	ft_freemap(array);
	ft_error(n);
}
