/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:58:32 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:58:37 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

static size_t	ft_strlen(char	*s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (s[0] == '+')
		i--;
	return (i);
}

static int	checknumber(char	*s)
{
	int	i;

	if (!s)
		return (0);
	if (!(s[0] == '+' || ft_isdigit(s[0])))
		return (0);
	if ((s[0] == '+') && !ft_isdigit(s[1]))
		return (0);
	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	checkarg(char	**argv, int i, long long	*value)
{
	size_t				len;
	unsigned long long	num;

	if (!value || !argv)
		return (0);
	if (!checknumber(argv[i]))
		return (0);
	len = ft_strlen(argv[i]);
	if (len > LLMAX_DIGITS)
		return (0);
	num = atoull(argv[i]);
	if (num > LLONG_MAX)
		return (0);
	if (!num && (i != 4))
		return (0);
	*value = (long long) num;
	return (1);
}

int	parsearg(int argc, char	**argv, t_data	*data)
{
	if (!argv || !data)
		return (0);
	if (!checkarg(argv, 1, &data->philonum))
		return (0);
	if (!checkarg(argv, 2, &data->dietime))
		return (0);
	if (!checkarg(argv, 3, &data->eatime))
		return (0);
	if (!checkarg(argv, 4, &data->sleeptime))
		return (0);
	data->numeat = -1;
	if (argc == 6)
	{
		if (!checkarg(argv, 5, &data->numeat))
			return (0);
	}
	return (1);
}
