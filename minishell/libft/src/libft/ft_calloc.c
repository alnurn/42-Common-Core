/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:43:11 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 18:47:29 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (!nmemb || !size)
	{
		ptr = (void *) malloc(1);
		if (!ptr)
			return (NULL);
		((unsigned char *) ptr)[0] = 0;
		return ((void *) ptr);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = (void *) malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *) ptr)[i] = 0;
		i++;
	}
	return ((void *) ptr);
}
