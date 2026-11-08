/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:59:18 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:22 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_usleep(time_t milliseconds)
{
	time_t	start;

	start = get_current_time();
	while ((get_current_time() - start < milliseconds))
		usleep(500);
}

time_t	get_current_time(void)
{
	struct timeval	time;
	time_t			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milliseconds);
}

void	waitstart(t_table	*table)
{
	time_t	current;

	if (!table)
		return ;
	current = get_current_time();
	if (current > table->start)
		return ;
	ft_usleep(table->start - current);
}
