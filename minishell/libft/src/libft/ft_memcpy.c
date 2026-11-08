/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 13:39:58 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 14:27:03 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void	*src, size_t n)
{
	unsigned char			*dptr;
	const unsigned char		*sptr;
	size_t					i;

	if (!dest || !src)
		return (dest);
	if (dest == src)
		return (dest);
	i = 0;
	dptr = (unsigned char *) dest;
	sptr = (const unsigned char *) src;
	while (i < n)
	{
		dptr[i] = sptr[i];
		i++;
	}
	return (dest);
}
