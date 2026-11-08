/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:36:24 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 16:09:59 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!s)
		return ;
	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
