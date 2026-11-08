/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:59:18 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:22 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checkdeath(t_data	*data)
{
	pthread_mutex_lock(&data->death);
	if (data->dead)
	{
		pthread_mutex_unlock(&data->death);
		return (1);
	}
	pthread_mutex_unlock(&data->death);
	return (0);
}

void	printmessage(t_data	*data, int id, const char	*str)
{
	long long	tstamp;

	pthread_mutex_lock(&data->message);
	if (!checkdeath(data))
	{
		tstamp = get_current_time() - data->start;
		printf("%lli %i %s\n", tstamp, id, str);
	}
	pthread_mutex_unlock(&data->message);
}

int	ft_usleep(t_data	*data, long long milliseconds)
{
	long long	start;

	start = get_current_time();
	while (!checkdeath(data) && (get_current_time() - start < milliseconds))
		usleep(500);
	return (0);
}

long long	get_current_time(void)
{
	struct timeval	time;
	long long		milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = (long long)(time.tv_sec * 1000 + time.tv_usec / 1000);
	return (milliseconds);
}
