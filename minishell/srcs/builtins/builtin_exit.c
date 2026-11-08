/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char) str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	exit_bad_arg(t_shell *shell, char *arg)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	shell->should_exit = 1;
	shell->exit_status = 2;
	return (2);
}

int	builtin_exit(char **args, t_shell *shell)
{
	long	code;

	if (isatty(STDIN_FILENO))
		ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (args[1] && !is_numeric(args[1]))
		return (exit_bad_arg(shell, args[1]));
	if (args[1] && args[2])
		return (ft_putstr_fd("minishell: exit: too many arguments\n",
				STDERR_FILENO), 1);
	code = shell->exit_status;
	if (args[1])
		code = ft_atol(args[1]);
	shell->should_exit = 1;
	shell->exit_status = (int)(code & 255);
	return (shell->exit_status);
}
