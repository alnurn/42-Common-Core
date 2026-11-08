/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoull.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:57:35 by anurmach          #+#    #+#             */
/*   Updated: 2026/05/16 17:57:41 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	atoull(char	*nptr)
{
	size_t				i;
	unsigned long long	num;

	i = 0;
	num = 0;
	if (!nptr)
		return (0);
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = 10 * num + (nptr[i] - '0');
		i++;
	}
	return (num);
}
