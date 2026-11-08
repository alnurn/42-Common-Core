/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:59:58 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 18:00:06 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	dream(t_philo	*philo)
{
	printmessage(philo->data, philo->id, "is sleeping");
	ft_usleep(philo->data, philo->data->sleeptime);
}

static void	think(t_philo	*philo)
{
	long long	thinktime;

	printmessage(philo->data, philo->id, "is thinking");
	if (!(philo->data->philonum % 2))
		return ;
	thinktime = philo->data->eatime * 2 - philo->data->sleeptime;
	if (thinktime < 0)
		thinktime = 0;
	ft_usleep(philo->data, thinktime);
}

static void	eat(t_philo	*philo)
{
	if (philo->data->philonum == 1)
	{
		onephilo(philo);
		return ;
	}
	lockforks(philo);
	printmessage(philo->data, philo->id, "is eating");
	pthread_mutex_lock(&philo->food);
	philo->eating = 1;
	philo->eaten++;
	philo->lasteat = get_current_time();
	pthread_mutex_unlock(&philo->food);
	ft_usleep(philo->data, philo->data->eatime);
	unlockforks(philo);
	pthread_mutex_lock(&philo->food);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->food);
}

void	*routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	if (philo->id % 2)
		ft_usleep(philo->data, philo->data->eatime);
	while (!checkdeath(philo->data))
	{
		eat(philo);
		think(philo);
		dream(philo);
	}
	return (NULL);
}
