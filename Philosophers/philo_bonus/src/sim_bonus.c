/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:58:54 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:06 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	init_table(t_table *table)
{
	int	i;

	if (!table)
		return (0);
	table->pids = (pid_t *) malloc (table->philonum * sizeof(pid_t));
	if (!table->pids)
		return (0);
	i = 0;
	while (i < table->philonum)
	{
		table->pids[i] = -1;
		i++;
	}
	table->start = get_current_time() + (table->philonum * 4);
	if (!open_global_sems(table))
		return (free(table->pids), 0);
	return (1);
}

static void	wait_for_processes(t_table	*table)
{
	int	i;

	i = 0;
	while (i < table->philonum)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
	sem_post(table->sem_dead);
}

int	sim(t_table	*table)
{
	int		i;
	pid_t	pid;

	if (!init_table(table))
		return (0);
	i = 0;
	while (i < table->philonum)
	{
		pid = fork();
		if (pid < 0)
			return (kill_all(table), free(table->pids), 0);
		if (!pid)
			philo(table, i);
		if (pid > 0)
			table->pids[i] = pid;
		i++;
	}
	if (table->philonum > 1)
		pthread_create(&table->killer, NULL, killer_routine, table);
	wait_for_processes(table);
	if (table->philonum > 1)
		pthread_join(table->killer, NULL);
	close_global_sems(table);
	free(table->pids);
	return (1);
}
