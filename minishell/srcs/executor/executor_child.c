/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dup_pipe_fds(int *fds)
{
	if (fds[2] != -1)
		close(fds[2]);
	if (fds[0] != -1)
	{
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
	if (fds[1] != -1)
	{
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
	}
}

static int	not_found_status(char *name)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	if (ft_strchr(name, '/') && access(name, F_OK) == 0)
		return (ft_putstr_fd(": Permission denied\n", STDERR_FILENO), 126);
	return (ft_putstr_fd(": command not found\n", STDERR_FILENO), 127);
}

static void	child_exit(t_shell *shell, int status)
{
	free_env(&shell->env);
	free_pipeline(&shell->current_pipeline);
	free(shell->pending_pids);
	exit(status);
}

static void	exec_or_builtin(t_cmd *cmd, t_shell *shell)
{
	char	*path;
	char	**envp;
	int		status;

	if (is_builtin(cmd->args[0]))
		child_exit(shell, run_builtin(cmd, shell));
	path = find_executable(cmd->args[0], shell->env);
	if (!path)
		child_exit(shell, not_found_status(cmd->args[0]));
	envp = build_envp(shell->env);
	execve(path, cmd->args, envp);
	perror("minishell");
	status = 126;
	free(path);
	free_charr(envp);
	child_exit(shell, status);
}

void	run_child(t_cmd *cmd, t_shell *shell, int *fds)
{
	dup_pipe_fds(fds);
	if (!apply_redirs(cmd))
		child_exit(shell, 1);
	if (!cmd->args || !cmd->args[0])
		child_exit(shell, 0);
	exec_or_builtin(cmd, shell);
}
