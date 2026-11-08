/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_syntax_error(int errorcode, char *str)
{
	if (errorcode == ERR_UNCLOSED_QUOTES)
	{
		ft_putstr_fd("-minishell: syntax error unclosed quotes\n",
			STDERR_FILENO);
		return ;
	}
	if (errorcode == ERR_UNEXPECTED_NEWLINE)
	{
		ft_putstr_fd("-minishell: syntax error near unexpected token ",
			STDERR_FILENO);
		ft_putstr_fd("'newline'\n", STDERR_FILENO);
		return ;
	}
	if (errorcode == ERR_UNEXPECTED_TOKEN && str)
	{
		ft_putstr_fd("-minishell: syntax error near unexpected token '",
			STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putstr_fd("'\n", STDERR_FILENO);
	}
}

int	is_unsupported(t_token_type type)
{
	if (type == TOK_AND || type == TOK_OR
		|| type == TOK_PARENTHESIS_OPEN || type == TOK_PARENTHESIS_CLOSE)
		return (1);
	else
		return (0);
}

int	is_redir(t_token_type type)
{
	if (type == TOK_REDIR_INPUT || type == TOK_REDIR_OUTPUT
		|| type == TOK_HEREDOC || type == TOK_REDIR_APPEND)
		return (1);
	else
		return (0);
}

int	check_pipe(t_token	*prev, t_token	*current)
{
	t_token	*next;

	next = current->next;
	if (!prev)
		return (print_syntax_error(ERR_UNEXPECTED_TOKEN, current->token), 0);
	if (!next)
		return (print_syntax_error(ERR_UNEXPECTED_NEWLINE, NULL), 0);
	if (next->type == TOK_PIPE)
		return (print_syntax_error(ERR_UNEXPECTED_TOKEN, next->token), 0);
	return (1);
}

int	check_redir(t_token	*current)
{
	t_token	*next;

	next = current->next;
	if (!next)
		return (print_syntax_error(ERR_UNEXPECTED_NEWLINE, NULL), 0);
	if (next->type != TOK_WORD)
		return (print_syntax_error(ERR_UNEXPECTED_TOKEN, next->token), 0);
	return (1);
}
