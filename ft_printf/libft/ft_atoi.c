/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:49:15 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 18:12:35 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skipspaces(const char	*nptr)
{
	size_t	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	return (i);
}

int	ft_atoi(const char	*nptr)
{
	size_t	i;
	int		m;
	int		num;
	int		n;

	i = 0;
	m = 1;
	num = 0;
	if (!nptr)
		return (0);
	i = ft_skipspaces(nptr);
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
