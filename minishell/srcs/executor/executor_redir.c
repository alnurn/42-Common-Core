/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_and_dup(char *file, int flags, int target_fd)
{
	int	fd;

	fd = open(file, flags, 0644);
	if (fd < 0)
		return (perror("minishell"), 0);
	if (dup2(fd, target_fd) < 0)
		return (close(fd), 0);
	close(fd);
	return (1);
}

static int	apply_one_redir(t_redir *redir)
{
	if (redir->type == TOK_REDIR_INPUT)
		return (open_and_dup(redir->file, O_RDONLY, redir->fd));
	if (redir->type == TOK_HEREDOC)
	{
		if (!open_and_dup(redir->file, O_RDONLY, redir->fd))
			return (unlink(redir->file), 0);
		return (unlink(redir->file), 1);
	}
	if (redir->type == TOK_REDIR_APPEND)
		return (open_and_dup(redir->file, O_WRONLY | O_CREAT | O_APPEND,
				redir->fd));
	return (open_and_dup(redir->file, O_WRONLY | O_CREAT | O_TRUNC,
			redir->fd));
}

int	apply_redirs(t_cmd *cmd)
{
	t_redir	*redir;

	redir = cmd->redirs;
	while (redir)
	{
		if (!apply_one_redir(redir))
			return (0);
		redir = redir->next;
	}
	return (1);
}
