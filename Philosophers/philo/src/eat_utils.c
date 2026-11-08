/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:57:54 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:57:58 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	onephilo(t_philo	*philo)
{
	if (!philo)
		return ;
	pthread_mutex_lock(philo->left_fork);
	printmessage(philo->data, philo->id, "has taken a fork");
	ft_usleep(philo->data, philo->data->dietime);
	pthread_mutex_unlock(philo->left_fork);
}

void	lockforks(t_philo	*philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_lock(philo->left_fork);
		printmessage(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		printmessage(philo->data, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		printmessage(philo->data, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		printmessage(philo->data, philo->id, "has taken a fork");
	}
}

void	unlockforks(t_philo	*philo)
{
	if (philo->left_fork < philo->right_fork)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}
