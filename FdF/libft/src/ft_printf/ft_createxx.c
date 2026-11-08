/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createxx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:45:42 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/15 15:52:20 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(unsigned int u, char	*dst, const char	*s, int len)
{
	if (u > HEX_BASE - 1)
		ft_putnbr(u / HEX_BASE, dst, s, len - 1);
	dst[len] = s[u % HEX_BASE];
}

t_strlen	ft_createxx(unsigned int u, char convers)
{
	t_strlen	str;
	const char	*s;

	str.len = ft_numlenu(u, HEX_BASE);
	str.str = (char *) malloc((str.len + 1) * sizeof(char));
	if (!str.str)
	{
		str.len = 0;
		return (str);
	}
	str.str[str.len] = '\0';
	if (convers == 'X')
	{
		s = "0123456789ABCDEF";
		ft_putnbr(u, str.str, s, str.len - 1);
	}
	else
	{
		s = "0123456789abcdef";
		ft_putnbr(u, str.str, s, str.len - 1);
	}
	return (str);
}
