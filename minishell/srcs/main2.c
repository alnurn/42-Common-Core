/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*read_line_interactive(void)
{
	char	*line;

	set_signals_prompt();
	line = readline("minishell$ ");
	if (!line)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (NULL);
	}
	if (line[0])
		add_history(line);
	return (line);
}

char	*read_line(void)
{
	if (isatty(STDIN_FILENO))
		return (read_line_interactive());
	return (silent_reader());
}

static void	abort_on_syntax_error(t_shell *shell)
{
	if (isatty(STDIN_FILENO))
		return ;
	shell_cleanup(shell);
	exit(2);
}

void	run_line(char *line, t_shell *shell)
{
	t_token	*tokens;
	t_cmd	*pipeline;

	tokens = get_tokens(line);
	free(line);
	if (!tokens)
		return ;
	if (!validator(tokens))
	{
		tok_lstclear(&tokens, free);
		shell->exit_status = 2;
		abort_on_syntax_error(shell);
		return ;
	}
	pipeline = parse_tokens(tokens);
	tok_lstclear(&tokens, free);
	if (!pipeline)
		return ;
	if (expand_pipeline(pipeline, shell))
		execute_pipeline(pipeline, shell);
	else
		shell->exit_status = 1;
	free_pipeline(&pipeline);
}
