/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:49:15 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 18:12:35 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char	*nptr)
{
	size_t	i;
	long	num;
	int		m;
	int		n;

	i = 0;
	m = 1;
	num = 0;
	if (!nptr)
		return (0);
	if (nptr[i] == '-')
	{
		i++;
		m = -1;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = nptr[i] - '0';
		num = 10 * num + n;
		i++;
	}
	return (num * m);
}
