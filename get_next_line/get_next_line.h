/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:56:16 by anurmach          #+#    #+#             */
/*   Updated: 2025/07/12 20:56:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FDM
#  define FDM 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_struct
{
	char	*remainder[FDM];
	int		start[FDM];
}	t_buffer;

char	*get_next_line(int fd);
void	ft_strjoin(t_buffer	*buffer, char	*temp, int fd);
void	ft_clean(t_buffer	*buffer, char	*temp, int fd);
int		ft_findnl(t_buffer	*buffer, int bytes, int fd);
char	*ft_substr(t_buffer	*buffer, int end, int fd);

#endif
