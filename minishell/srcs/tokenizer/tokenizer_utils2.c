/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static t_token_type	get_operator_type2(char *token)
{
	if (!ft_strncmp((const char *) token, AND, 2))
		return (TOK_AND);
	if (!ft_strncmp((const char *) token, OR, 2))
		return (TOK_OR);
	if (token[0] == PIPE)
		return (TOK_PIPE);
	if (token[0] == PARENTHESIS_OPEN)
		return (TOK_PARENTHESIS_OPEN);
	if (token[0] == PARENTHESIS_CLOSE)
		return (TOK_PARENTHESIS_CLOSE);
	return (-1);
}

static t_token_type	get_operator_type(char *token)
{
	int	i;

	if (!token)
		return (-1);
	i = count_digits(token);
	if (!ft_strncmp((const char *) &token[i], HEREDOC, 2))
		return (TOK_HEREDOC);
	if (!ft_strncmp((const char *) &token[i], REDIR_APPEND, 2))
		return (TOK_REDIR_APPEND);
	if (token[i] == REDIR_INPUT)
		return (TOK_REDIR_INPUT);
	if (token[i] == REDIR_OUTPUT)
		return (TOK_REDIR_OUTPUT);
	return (get_operator_type2(token));
}

void	put_operator_types(t_token *list)
{
	t_token	*current;

	if (!list)
		return ;
	current = list;
	while (current)
	{
		if (current->type != TOK_WORD)
			current->type = get_operator_type(current->token);
		current = current->next;
	}
}
