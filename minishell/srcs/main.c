/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_shell(t_shell *shell, char **envp)
{
	shell->env = dup_env(envp);
	shell->exit_status = 0;
	shell->should_exit = 0;
	shell->current_pipeline = NULL;
	shell->line_number = 0;
	shell->pending_pids = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;

	(void) argc;
	(void) argv;
	init_shell(&shell, envp);
	while (1)
	{
		line = read_line();
		if (!line)
			break ;
		shell.line_number++;
		run_line(line, &shell);
		if (shell.should_exit)
			break ;
	}
	shell_cleanup(&shell);
	return (shell.exit_status);
}
