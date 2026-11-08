/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 12:04:58 by anurmach          #+#    #+#             */
/*   Updated: 2025/06/14 20:27:25 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revstrcpy(t_strlen	*str, int n, const char *src, char c)
{
	int	i;

	i = str->len - 1;
	if (!str || !str->str)
		return ;
	n--;
	while (i >= 0)
	{
		str->str[n] = src[i];
		i--;
		n--;
	}
	while (n >= 0)
	{
		str->str[n] = c;
		n--;
	}
}
