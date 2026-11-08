/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:59:18 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:22 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	dream(t_table	*table)
{
	printmessage(table, SLEEP);
	ft_usleep(table->sleeptime);
}

void	think(t_table	*table)
{
	time_t	thinktime;

	printmessage(table, THINK);
	if (!(table->philonum & 1))
		return ;
	thinktime = table->eatime * 2 - table->sleeptime;
	if (thinktime < 0)
		thinktime = 0;
	ft_usleep(thinktime);
}

static void	eat2(t_table	*table, int num_eat, int philo_eaten)
{
	sem_post(table->philo->sem_food);
	ft_usleep(table->eatime);
	sem_post(table->sem_forks);
	sem_post(table->sem_forks);
	if ((num_eat > 0) && (philo_eaten >= num_eat))
		exit_child0(table);
	sem_wait(table->philo->sem_food);
	table->philo->eating = 0;
	sem_post(table->philo->sem_food);
}

void	eat(t_table	*table)
{
	int	num_eat;
	int	philo_eaten;

	num_eat = -1;
	philo_eaten = -1;
	sem_wait(table->sem_forks);
	printmessage(table, TAKEFORK);
	sem_wait(table->sem_forks);
	printmessage(table, TAKEFORK);
	printmessage(table, EAT);
	sem_wait(table->philo->sem_food);
	table->philo->eating = 1;
	table->philo->lasteat = get_current_time();
	table->philo->eaten++;
	if ((table->numeat > 0))
	{
		num_eat = table->numeat;
		philo_eaten = table->philo->eaten;
	}
	eat2(table, num_eat, philo_eaten);
}
