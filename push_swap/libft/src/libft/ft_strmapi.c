/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:53:10 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 21:55:20 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*dst;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	dst = (char *) malloc((i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = f((unsigned int) i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
