/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createaddr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:18:54 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/15 19:57:56 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(uintptr_t	addr)
{
	int	count;

	count = 0;
	while (addr)
	{
		addr /= HEX_BASE;
		count++;
	}
	count += 2;
	return (count);
}

static void	ft_puthex(uintptr_t addr, char	*dst, int len)
{
	char	*c;

	c = "0123456789abcdef";
	if (addr > HEX_BASE - 1)
		ft_puthex(addr / HEX_BASE, dst, len - 1);
	dst[len] = c[addr % HEX_BASE];
}

static t_strlen	ft_createad(void	*ptr, t_struct	*data)
{
	t_strlen		str;
	unsigned char	*p;
	uintptr_t		addr;

	p = (unsigned char *) ptr;
	addr = (uintptr_t) & p[0];
	str.len = ft_count(addr);
	str.str = (char *) malloc((str.len + 1) * sizeof(char));
	if (!str.str)
	{
		str.len = 0;
		return (str);
	}
	str.str[str.len] = '\0';
	str.str[0] = '0';
	str.str[1] = 'x';
	ft_puthex(addr, str.str, str.len - 1);
	ft_strwidth(&str, data, ' ');
	return (str);
}

t_strlen	ft_createaddr(void	*ptr, t_struct	*data)
{
	t_strlen		str;

	if (!ptr)
	{
		str.str = ft_strdup("(nil)");
		str.len = 5;
		ft_strwidth(&str, data, ' ');
		return (str);
	}
	str = ft_createad(ptr, data);
	return (str);
}
