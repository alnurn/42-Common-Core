/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 18:00:17 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 18:00:22 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philoinit(t_data	*data)
{
	long long	i;

	data->philos = (t_philo *) malloc(data->philonum * sizeof(t_philo));
	if (!data->philos)
		return ;
	i = 0;
	while (i < data->philonum)
	{
		data->philos[i].id = (int) i + 1;
		data->philos[i].eaten = 0;
		data->philos[i].eating = 0;
		data->philos[i].lasteat = data->start;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->philos[i].fork;
		if (!i)
			data->philos[i].right_fork = &data->philos[data->philonum - 1].fork;
		else
			data->philos[i].right_fork = &data->philos[i - 1].fork;
		i++;
	}
}

void	sim(t_data	*data)
{
	if (!data)
		return ;
	data->philos = NULL;
	data->dead = 0;
	data->start = get_current_time();
	philoinit(data);
	if (!data->philos)
		return ;
	mutexinit(data);
	pthreadcreate(data);
	pthreadjoin(data);
	mutexdestroy(data);
	free(data->philos);
}
