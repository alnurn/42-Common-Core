/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:48:43 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 21:51:56 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
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

char	*ft_itoa(int n)
{
	size_t	len;
	char	*dst;

	len = ft_numlen(n);
	if (n < 0)
		len++;
	dst = (char *) malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_putnbr((long) n, dst, len - 1);
	dst[len] = '\0';
	return (dst);
}
