/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:40:16 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 16:44:58 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	size_t			i;
	unsigned char	n;

	if (!s)
		return (NULL);
	i = 0;
	n = (unsigned char) c;
	while (s[i])
	{
		if (n == (unsigned char) s[i])
			return ((char *) &s[i]);
		i++;
	}
	if (n == (unsigned char) s[i])
		return ((char *) &s[i]);
	return (NULL);
}
