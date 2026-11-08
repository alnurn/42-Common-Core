/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:58:54 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:06 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char	**argv)
{
	t_table	table;
	t_philo	philo;

	memset(&table, 0, sizeof(t_table));
	memset(&philo, 0, sizeof(t_philo));
	if ((argc != 5 && argc != 6) || !parsearg(argc, argv, &table))
	{
		print_error(1);
		return (1);
	}
	table.philo = &philo;
	if (!sim(&table))
	{
		print_error(2);
		return (2);
	}
	return (0);
}
