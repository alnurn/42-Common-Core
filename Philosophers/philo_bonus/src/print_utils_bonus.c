/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:59:18 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:22 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_error(int errorcode)
{
	if (errorcode == 1)
		printf("%s", ERROR);
	else if (errorcode == 2)
		printf("%s", SIM_ERROR);
}

void	printmessage(t_table	*table, const char	*str)
{
	time_t	tstamp;

	if (!table || !table->philo || !str)
		return ;
	sem_wait(table->sem_print);
	tstamp = get_current_time() - table->start;
	printf("%li %i %s\n", tstamp, table->philo->id, str);
	sem_post(table->sem_print);
}

void	printdeath(t_table	*table, const char	*str)
{
	time_t	tstamp;

	if (!table || !table->philo || !str)
		return ;
	sem_wait(table->sem_print);
	tstamp = get_current_time() - table->start;
	printf("%li %i %s\n", tstamp, table->philo->id, str);
	sem_post(table->sem_dead);
}
