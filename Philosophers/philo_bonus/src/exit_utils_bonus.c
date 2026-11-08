/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:58:54 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:06 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	kill_all(t_table	*table)
{
	int		i;

	if (!table)
		return ;
	i = 0;
	while (i < table->philonum)
	{
		if (table->pids[i] > 0)
			kill(table->pids[i], SIGKILL);
		i++;
	}
}

void	exit_child0(t_table	*table)
{
	if (!table)
		return ;
	pthread_join(table->philo->monitor, NULL);
	close_global_sems(table);
	close_local_sems(table);
	free(table->pids);
	exit (0);
}

void	exit_child1(t_table	*table)
{
	if (!table)
		return ;
	close_global_sems(table);
	close_local_sems(table);
	free(table->pids);
	exit(1);
}
