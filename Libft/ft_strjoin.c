/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:56:23 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 21:12:08 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_join(char	*dst, char const	*s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	dst = (char *) malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	i = ft_join(&dst[0], s1);
	i += ft_join(&dst[i], s2);
	dst[i] = '\0';
	return (dst);
}
