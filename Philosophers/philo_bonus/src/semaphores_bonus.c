/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:58:54 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:06 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	open_global_sems(t_table	*table)
{
	if (!table)
		return (0);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_DEAD);
	table->sem_print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	if (table->sem_print == SEM_FAILED)
		return (0);
	table->sem_forks = sem_open(SEM_FORKS, O_CREAT, 0644, table->philonum);
	if (table->sem_forks == SEM_FAILED)
		return (0);
	table->sem_dead = sem_open(SEM_DEAD, O_CREAT, 0644, 0);
	if (table->sem_dead == SEM_FAILED)
		return (0);
	return (1);
}

void	close_global_sems(t_table	*table)
{
	if (!table)
		return ;
	sem_close(table->sem_print);
	sem_close(table->sem_forks);
	sem_close(table->sem_dead);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_DEAD);
}

int	open_local_sems(t_table	*table)
{
	if (!table)
		return (0);
	sem_unlink(table->philo->food_name);
	table->philo->sem_food = sem_open(table->philo->food_name,
			O_CREAT, 0644, 1);
	if (table->philo->sem_food == SEM_FAILED)
		return (0);
	return (1);
}

void	close_local_sems(t_table	*table)
{
	if (!table)
		return ;
	sem_close(table->philo->sem_food);
	sem_unlink(table->philo->food_name);
}
