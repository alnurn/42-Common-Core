/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_single.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	run_in_parent(t_cmd *cmd, t_shell *shell)
{
	int	saved_in;
	int	saved_out;
	int	status;

	saved_in = dup(STDIN_FILENO);
	saved_out = dup(STDOUT_FILENO);
	status = 1;
	if (apply_redirs(cmd))
	{
		status = 0;
		if (cmd->args && cmd->args[0])
			status = run_builtin(cmd, shell);
	}
	dup2(saved_in, STDIN_FILENO);
	dup2(saved_out, STDOUT_FILENO);
	close(saved_in);
	close(saved_out);
	return (status);
}

static int	run_external_single(t_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
	int		status;
	int		fds[3];

	fds[0] = -1;
	fds[1] = -1;
	fds[2] = -1;
	pid = fork_one(cmd, shell, fds);
	set_signals_parent();
	status = wait_children(&pid, 1);
	set_signals_prompt();
	return (status);
}

int	execute_single(t_cmd *cmd, t_shell *shell)
{
	if (cmd->args && cmd->args[0] && !is_builtin(cmd->args[0]))
		return (run_external_single(cmd, shell));
	return (run_in_parent(cmd, shell));
}
