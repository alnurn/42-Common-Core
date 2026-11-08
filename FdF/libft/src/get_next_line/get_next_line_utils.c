/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:56:42 by anurmach          #+#    #+#             */
/*   Updated: 2025/07/12 21:08:59 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean(t_buffer	*buffer, char	*temp, int fd)
{
	free(buffer->remainder[fd]);
	buffer->remainder[fd] = NULL;
	buffer->start[fd] = 0;
	if (temp)
		free(temp);
}

size_t	ft_join(char	*dst, char	*s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	return (i);
}

void	ft_stringjoin(t_buffer	*buffer, char	*temp, int fd)
{
	size_t	lr;
	size_t	lt;
	size_t	i;
	char	*dst;

	lr = 0;
	lt = 0;
	if (buffer->remainder[fd])
	{
		while (buffer->remainder[fd][lr])
			lr++;
	}
	while (temp[lt])
		lt++;
	dst = (char *) malloc((lr + lt + 1) * sizeof(char));
	if (!dst)
	{
		ft_clean(buffer, temp, fd);
		return ;
	}
	i = ft_join(&dst[0], buffer->remainder[fd]);
	i += ft_join(&dst[i], temp);
	dst[i] = '\0';
	free(buffer->remainder[fd]);
	buffer->remainder[fd] = dst;
}

int	ft_findnl(t_buffer	*buffer, int bytes, int fd)
{
	int	i;

	if (!buffer->remainder[fd])
		return (-1);
	i = buffer->start[fd];
	while (buffer->remainder[fd][i])
	{
		if (buffer->remainder[fd][i] == '\n')
			return (i);
		i++;
	}
	if (!bytes)
		return (i - 1);
	return (-1);
}

char	*ft_substring(t_buffer	*buffer, int end, int fd)
{
	char	*dst;
	int		i;
	int		size;

	if (!buffer->remainder[fd])
		return (NULL);
	if (end >= buffer->start[fd])
	{
		size = end - buffer->start[fd] + 2;
		i = 0;
		dst = (char *) malloc(size * sizeof(char));
		if (!dst)
			return (NULL);
		while (i < size - 1)
		{
			dst[i] = buffer->remainder[fd][buffer->start[fd] + i];
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	ft_clean(buffer, NULL, fd);
	return (NULL);
}
