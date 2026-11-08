/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*generate_tempname(void)
{
	static int	counter = 0;
	char		*num;
	char		*name;

	num = ft_itoa(counter++);
	if (!num)
		return (NULL);
	name = ft_strjoin("/tmp/.minishell_heredoc_", num);
	free(num);
	return (name);
}

static void	print_eof_warning(char *delim, int line_number)
{
	char	*num;

	num = ft_itoa(line_number);
	ft_putstr_fd("minishell: warning: here-document at line ", STDERR_FILENO);
	if (num)
		ft_putstr_fd(num, STDERR_FILENO);
	ft_putstr_fd(" delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(delim, STDERR_FILENO);
	ft_putstr_fd("')\n", STDERR_FILENO);
	free(num);
}

static int	read_heredoc_body(char *delim, int quoted, t_shell *shell, int fd)
{
	char	*line;
	char	*expanded;

	g_signal = 0;
	set_signals_heredoc();
	while (1)
	{
		line = read_heredoc_line();
		if (g_signal == SIGINT)
			return (free(line), 0);
		if (!line)
			return (print_eof_warning(delim, shell->line_number), 1);
		if (!ft_strncmp(line, delim, ft_strlen(delim) + 1))
			return (free(line), 1);
		if (!quoted)
			expanded = expand_heredoc_line(line, shell);
		else
			expanded = ft_strdup(line);
		free(line);
		write(fd, expanded, ft_strlen(expanded));
		write(fd, "\n", 1);
		free(expanded);
	}
}

static int	run_one_heredoc(t_redir *redir, t_shell *shell)
{
	char	*temp_name;
	int		fd;
	int		flag;

	temp_name = generate_tempname();
	if (!temp_name)
		return (0);
	fd = open(temp_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (free(temp_name), 0);
	flag = read_heredoc_body(redir->file, redir->quoted, shell, fd);
	close(fd);
	if (!flag)
		return (unlink(temp_name), free(temp_name), 0);
	free(redir->file);
	redir->file = temp_name;
	return (1);
}

int	run_heredocs(t_cmd *pipeline, t_shell *shell)
{
	t_redir	*redir;

	while (pipeline)
	{
		redir = pipeline->redirs;
		while (redir)
		{
			if (redir->type == TOK_HEREDOC && !run_one_heredoc(redir, shell))
				return (set_signals_prompt(), 0);
			redir = redir->next;
		}
		pipeline = pipeline->next;
	}
	return (set_signals_prompt(), 1);
}
