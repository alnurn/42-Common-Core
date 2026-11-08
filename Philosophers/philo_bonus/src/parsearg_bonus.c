/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:58:32 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:58:37 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	checknumber(char	*s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	mini_atoi(char	*nptr)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	if (!nptr)
		return (-1);
	if (nptr[i] == '+')
		i++;
	if (!checknumber(&nptr[i]))
		return (-1);
	while (nptr[i] && (i < 9))
	{
		num = 10 * num + (nptr[i] - '0');
		i++;
	}
	if (num > MAX_VALUE)
		return (-1);
	return (num);
}

static int	checkarg(char	**argv, int i, t_table	*table)
{
	int	num;

	if (!table || !argv)
		return (0);
	num = mini_atoi(argv[i]);
	if ((!num && (i != 4)) || (num < 0) || (i == 1 && num > MAX_PHILO))
		return (0);
	if (i == 1)
		table->philonum = num;
	else if (i == 2)
		table->dietime = (time_t) num;
	else if (i == 3)
		table->eatime = (time_t) num;
	else if (i == 4)
		table->sleeptime = (time_t) num;
	else if (i == 5)
		table->numeat = num;
	return (1);
}

int	parsearg(int argc, char	**argv, t_table	*table)
{
	if (!argv || !table)
		return (0);
	if (!checkarg(argv, 1, table))
		return (0);
	if (!checkarg(argv, 2, table))
		return (0);
	if (!checkarg(argv, 3, table))
		return (0);
	if (!checkarg(argv, 4, table))
		return (0);
	table->numeat = -1;
	if (argc == 6)
	{
		if (!checkarg(argv, 5, table))
			return (0);
	}
	return (1);
}
