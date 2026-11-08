/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:58:10 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:58:14 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutexdestroy(t_data	*data)
{
	long long	i;

	if (!data)
		return ;
	i = 0;
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->message);
	while (i < data->philonum)
	{
		pthread_mutex_destroy(&data->philos[i].fork);
		pthread_mutex_destroy(&data->philos[i].food);
		i++;
	}
}

void	mutexinit(t_data	*data)
{
	long long	i;

	if (!data)
		return ;
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->message, NULL);
	i = 0;
	while (i < data->philonum)
	{
		pthread_mutex_init(&data->philos[i].fork, NULL);
		pthread_mutex_init(&data->philos[i].food, NULL);
		i++;
	}
}
