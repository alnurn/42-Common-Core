/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:00:32 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 18:00:35 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	if_philo_istarving(t_data	*data, long long index)
{
	pthread_mutex_lock(&data->philos[index].food);
	if ((get_current_time() - data->philos[index].lasteat >= data->dietime)
		&& !data->philos[index].eating)
	{
		pthread_mutex_unlock(&data->philos[index].food);
		return (1);
	}
	pthread_mutex_unlock(&data->philos[index].food);
	return (0);
}

static int	if_philo_isdead(t_data	*data)
{
	long long	i;

	i = 0;
	while (i < data->philonum)
	{
		if (if_philo_istarving(data, i))
		{
			printmessage(data, data->philos[i].id, "died");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	if_philos_eaten(t_data	*data)
{
	long long	i;
	long long	n;

	if (data->numeat < 0)
		return (0);
	i = 0;
	n = 0;
	while (i < data->philonum)
	{
		pthread_mutex_lock(&data->philos[i].food);
		if (data->philos[i].eaten >= data->numeat)
			n++;
		pthread_mutex_unlock(&data->philos[i].food);
		i++;
	}
	if (n == data->philonum)
		return (1);
	return (0);
}

void	*track(void	*arg)
{
	t_data	*data;

	data = (t_data *) arg;
	while (1)
	{
		if (if_philos_eaten(data) || if_philo_isdead(data))
		{
			pthread_mutex_lock(&data->death);
			data->dead = 1;
			pthread_mutex_unlock(&data->death);
			break ;
		}
	}
	return (NULL);
}
