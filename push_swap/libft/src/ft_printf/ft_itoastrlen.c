/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoastrlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:18:05 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/14 20:16:39 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	if (!n)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putnbr(long n, char	*dst, int len)
{
	int	remainder;

	if (n < 0)
	{
		dst[0] = '-';
		n = -n;
	}
	remainder = n % 10;
	if (n > 9)
		ft_putnbr(n / 10, dst, len - 1);
	dst[len] = remainder + '0';
}

t_strlen	ft_itoastrlen(int n)
{
	t_strlen	str;

	str.len = ft_numlen(n);
	if (n < 0)
		str.len++;
	str.str = (char *) malloc((str.len + 1) * sizeof(char));
	if (!str.str)
	{
		str.len = 0;
		return (str);
	}
	ft_putnbr((long) n, str.str, str.len - 1);
	str.str[str.len] = '\0';
	return (str);
}
