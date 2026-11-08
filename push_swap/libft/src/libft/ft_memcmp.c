/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:07:03 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 17:17:11 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	if (!n || (!s1 && !s2))
		return (0);
	ptr1 = (const unsigned char *) s1;
	ptr2 = (const unsigned char *) s2;
	if (!s1 && s2)
		return (ptr2[0]);
	if (!s2 && s1)
		return (ptr1[0]);
	i = 0;
	while (ptr1[i] == ptr2[i] && i < n - 1)
		i++;
	return (ptr1[i] - ptr2[i]);
}
