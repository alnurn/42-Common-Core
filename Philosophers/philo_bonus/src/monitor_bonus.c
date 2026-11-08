/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:58:54 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:06 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	if_philo_full(t_table	*table)
{
	int	num_eat;
	int	philo_eaten;

	num_eat = -1;
	philo_eaten = -1;
	sem_wait(table->philo->sem_food);
	if ((table->numeat > 0))
	{
		num_eat = table->numeat;
		philo_eaten = table->philo->eaten;
	}
	sem_post(table->philo->sem_food);
	if ((num_eat > 0) && (philo_eaten >= num_eat))
		return (1);
	return (0);
}

static int	if_philo_istarving(t_table	*table)
{
	sem_wait(table->philo->sem_food);
	if ((get_current_time() - table->philo->lasteat >= table->dietime)
		&& !table->philo->eating)
	{
		sem_post(table->philo->sem_food);
		return (1);
	}
	sem_post(table->philo->sem_food);
	return (0);
}

void	*monitor_routine(void	*data)
{
	t_table	*table;

	table = (t_table *) data;
	if (!table || !table->philo)
		return (NULL);
	waitstart(table);
	while (1)
	{
		if (if_philo_istarving(table))
		{
			printdeath(table, DIED);
			break ;
		}
		if (if_philo_full(table))
			break ;
		usleep(500);
	}
	return (NULL);
}

void	*killer_routine(void	*data)
{
	t_table	*table;

	table = (t_table *) data;
	if (!table || !table->philo)
		return (NULL);
	sem_wait(table->sem_dead);
	kill_all(table);
	return (NULL);
}
