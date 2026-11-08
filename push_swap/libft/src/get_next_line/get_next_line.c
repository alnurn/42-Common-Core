/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:36:15 by anurmach          #+#    #+#             */
/*   Updated: 2025/07/26 19:36:24 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_read(int fd, t_buffer	*buffer)
{
	char	*temp;
	int		i;
	int		bytes;

	i = 0;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
	{
		ft_clean(buffer, NULL, fd);
		return (-1);
	}
	while (i <= BUFFER_SIZE)
		temp[i++] = 0;
	bytes = read(fd, temp, BUFFER_SIZE);
	if (bytes < 0 || (!bytes && !buffer->remainder[fd]))
	{
		ft_clean(buffer, temp, fd);
		return (-1);
	}
	ft_stringjoin(buffer, temp, fd);
	free(temp);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static t_buffer	buffer;
	int				bytes;
	int				end;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	end = -1;
	while (1)
	{
		bytes = ft_read(fd, &buffer);
		if (bytes < 0)
			return (NULL);
		end = ft_findnl(&buffer, bytes, fd);
		if (end >= 0)
		{
			line = ft_substring(&buffer, end, fd);
			if (line)
				buffer.start[fd] = end + 1;
			break ;
		}
	}
	return (line);
}
