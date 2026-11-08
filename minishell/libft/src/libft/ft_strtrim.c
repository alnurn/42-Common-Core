/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:42:01 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 21:44:56 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	int			i;
	char const	*start;
	char const	*end;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	start = &s1[i];
	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_strchr(set, s1[i]))
		i--;
	end = &s1[i];
	if (start > end)
		return ((char *) ft_calloc(1, 1));
	i = (int)(end - start) + 1;
	return (ft_substr(start, 0, (size_t) i));
}
