/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *name)
{
	if (!name)
		return (0);
	return (!ft_strncmp(name, "echo", 5) || !ft_strncmp(name, "cd", 3)
		|| !ft_strncmp(name, "pwd", 4) || !ft_strncmp(name, "export", 7)
		|| !ft_strncmp(name, "unset", 6) || !ft_strncmp(name, "env", 4)
		|| !ft_strncmp(name, "exit", 5));
}

int	run_builtin(t_cmd *cmd, t_shell *shell)
{
	char	*name;

	name = cmd->args[0];
	if (!ft_strncmp(name, "echo", 5))
		return (builtin_echo(cmd->args));
	if (!ft_strncmp(name, "cd", 3))
		return (builtin_cd(cmd->args, shell));
	if (!ft_strncmp(name, "pwd", 4))
		return (builtin_pwd());
	if (!ft_strncmp(name, "export", 7))
		return (builtin_export(cmd->args, shell));
	if (!ft_strncmp(name, "unset", 6))
		return (builtin_unset(cmd->args, shell));
	if (!ft_strncmp(name, "env", 4))
		return (builtin_env(cmd->args, shell));
	return (builtin_exit(cmd->args, shell));
}
