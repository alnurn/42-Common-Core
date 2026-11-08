/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:48:07 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 16:20:28 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t sz)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	if (!src)
		return (0);
	while (src[src_len])
		src_len++;
	if (!sz || !dst)
		return (src_len);
	while (src[i] && i < sz - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
