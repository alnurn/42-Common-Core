/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:47:54 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 18:50:27 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char	*s)
{
	size_t	i;
	size_t	len;
	char	*cp;

	if (!s)
		return (NULL);
	len = 0;
	i = 0;
	while (s[len])
		len++;
	cp = (char *) malloc((len + 1) * sizeof(char));
	if (!cp)
		return (NULL);
	while (s[i] && i < len)
	{
		cp[i] = s[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
