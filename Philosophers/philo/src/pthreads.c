/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthreads.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:59:39 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:43 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pthreadjoin(t_data	*data)
{
	long long	i;

	if (!data)
		return ;
	i = 0;
	pthread_join(data->track, NULL);
	while (i < data->philonum)
	{
		pthread_join(data->philos[i].t, NULL);
		i++;
	}
}

void	pthreadcreate(t_data	*data)
{
	long long	i;

	if (!data)
		return ;
	i = 0;
	pthread_create(&data->track, NULL, track, data);
	while (i < data->philonum)
	{
		pthread_create(&data->philos[i].t, NULL, routine, &data->philos[i]);
		i++;
	}
}
