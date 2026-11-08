/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:58:54 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:59:06 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_putnbr(int nb, char	*dest, int i)
{
	if (nb > 9)
		ft_putnbr(nb / 10, dest, i + 1);
	dest[i] = nb % 10 + '0';
}

static size_t	ft_strcpy(char	*dest, char	*src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

static void	philo_routine(t_table	*table)
{
	if (!table || !table->philo)
		return ;
	waitstart(table);
	if (table->philo->id & 1)
		ft_usleep(table->eatime);
	while (1)
	{
		eat(table);
		think(table);
		dream(table);
	}
}

static void	alone_philo(t_table	*table)
{
	time_t	tstamp;

	waitstart(table);
	tstamp = get_current_time() - table->start;
	printf("%li %i %s\n", tstamp, table->philo->id, TAKEFORK);
	ft_usleep(table->dietime);
	tstamp = get_current_time() - table->start;
	printf("%li %i %s\n", tstamp, table->philo->id, DIED);
	close_global_sems(table);
	free(table->pids);
	exit (0);
}

void	philo(t_table	*table, int index)
{
	int	i;

	if (!table)
		return ;
	table->philo->id = index + 1;
	if (table->philonum == 1)
		alone_philo(table);
	i = ft_strcpy(table->philo->food_name, SEM_FOOD);
	ft_putnbr(table->philo->id, table->philo->food_name, i);
	table->philo->lasteat = table->start;
	if (!open_local_sems(table))
		exit_child1(table);
	pthread_create(&table->philo->monitor, NULL, monitor_routine, table);
	philo_routine(table);
}
