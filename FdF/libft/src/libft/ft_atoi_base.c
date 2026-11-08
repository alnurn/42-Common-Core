/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:10:50 by anurmach          #+#    #+#             */
/*   Updated: 2025/02/26 15:26:52 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findindex(char c, int len)
{
	int		i;
	char	*base;
	char	*base_upper;

	base = "0123456789absdef";
	base_upper = "0123456789ABCDEF";
	i = 0;
	while (base[i] && i < len)
	{
		if (c == base[i] || c == base_upper[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_makenum(char	*str, int base)
{
	size_t	i;
	int		number;
	int		index;

	if (!str)
		return (0);
	number = 0;
	i = 0;
	while (str[i])
	{
		index = ft_findindex(str[i], base);
		if (index >= 0)
			number = number * base + index;
		else
			break ;
		i++;
	}
	return (number);
}

int	ft_atoi_base(char	*str, int base)
{
	size_t	i;
	int		m;
	int		number;

	if (!str)
		return (0);
	i = 0;
	m = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		i++;
		m = -1;
	}
	else if (str[i] == '+')
		i++;
	number = ft_makenum(&str[i], base);
	return (m * number);
}
