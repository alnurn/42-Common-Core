/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_heredoc_read.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*strip_nl(char *line)
{
	size_t	len;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	if (len && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static char	*read_line_raw(void)
{
	char	c;
	char	*line;
	int		n;

	ft_putstr_fd("> ", STDOUT_FILENO);
	line = ft_strdup("");
	while (line)
	{
		n = read(STDIN_FILENO, &c, 1);
		if (n == 0)
			ft_putstr_fd("\n", STDOUT_FILENO);
		if (n <= 0)
			break ;
		if (c == '\n')
			return (line);
		line = join_free(line, ft_substr(&c, 0, 1));
	}
	if (!line || g_signal == SIGINT || !line[0])
		return (free(line), NULL);
	return (line);
}

char	*read_heredoc_line(void)
{
	if (isatty(STDIN_FILENO))
		return (read_line_raw());
	return (strip_nl(silent_reader()));
}
