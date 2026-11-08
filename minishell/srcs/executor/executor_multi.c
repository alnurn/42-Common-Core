/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmds(t_cmd *pipeline)
{
	int	count;

	count = 0;
	while (pipeline)
	{
		count++;
		pipeline = pipeline->next;
	}
	return (count);
}

static void	fork_all(t_cmd *pipeline, t_shell *shell, pid_t *pids)
{
	int	prev_fd;
	int	fd[2];
	int	fds[3];
	int	i;

	prev_fd = -1;
	i = 0;
	while (pipeline)
	{
		fd[0] = -1;
		fd[1] = -1;
		if (pipeline->next)
			pipe(fd);
		fds[0] = prev_fd;
		fds[1] = fd[1];
		fds[2] = fd[0];
		pids[i++] = fork_one(pipeline, shell, fds);
		if (prev_fd != -1)
			close(prev_fd);
		if (fd[1] != -1)
			close(fd[1]);
		prev_fd = fd[0];
		pipeline = pipeline->next;
	}
}

int	execute_multi(t_cmd *pipeline, t_shell *shell)
{
	int		count;
	pid_t	*pids;
	int		status;

	count = count_cmds(pipeline);
	pids = (pid_t *) malloc(sizeof(pid_t) * count);
	if (!pids)
		return (1);
	shell->pending_pids = pids;
	fork_all(pipeline, shell, pids);
	set_signals_parent();
	status = wait_children(pids, count);
	set_signals_prompt();
	shell->pending_pids = NULL;
	return (free(pids), status);
}
