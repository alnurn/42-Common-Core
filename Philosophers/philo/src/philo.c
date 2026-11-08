/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:58:54 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:06 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char	**argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
		return (1);
	memset(&data, 0, sizeof(t_data));
	if (!parsearg(argc, argv, &data))
		return (2);
	sim(&data);
	return (0);
}
