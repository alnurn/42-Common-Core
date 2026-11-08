/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cd_error(char *path)
{
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	return (1);
}

static void	update_pwd_vars(t_shell *shell, char *old_pwd)
{
	char	*new_pwd;

	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
	{
		env_set(&shell->env, "PWD", new_pwd);
		free(new_pwd);
	}
	if (old_pwd)
		env_set(&shell->env, "OLDPWD", old_pwd);
}

int	builtin_cd(char **args, t_shell *shell)
{
	char	*old_pwd;

	if (!args[1])
		return (ft_putstr_fd("minishell: cd: missing argument\n",
				STDERR_FILENO), 1);
	if (args[2])
		return (ft_putstr_fd("minishell: cd: too many arguments\n",
				STDERR_FILENO), 1);
	old_pwd = getcwd(NULL, 0);
	if (chdir(args[1]) == -1)
		return (free(old_pwd), cd_error(args[1]));
	update_pwd_vars(shell, old_pwd);
	return (free(old_pwd), 0);
}
