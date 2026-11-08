/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_end_quotes(char *str, char quote)
{
	size_t	i;

	if (!str)
		return (0);
	i = 1;
	while (str[i] && str[i] != quote)
		i++;
	return (i);
}

static int	check_quotes(char *str)
{
	int	i;
	int	open;
	int	len;

	if (!str)
		return (1);
	len = ft_strlen((const char *) str);
	open = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE)
		{
			open++;
			i += find_end_quotes(&str[i], str[i]);
			if (i < len)
				open--;
		}
		if (str[i])
			i++;
	}
	return (open);
}

static int	check_token(t_token	*prev, t_token	*current)
{
	if (is_unsupported(current->type))
		return (print_syntax_error(ERR_UNEXPECTED_TOKEN, current->token), 0);
	if (current->type == TOK_WORD && check_quotes(current->token))
		return (print_syntax_error(ERR_UNCLOSED_QUOTES, NULL), 0);
	if (current->type == TOK_PIPE)
		return (check_pipe(prev, current));
	if (is_redir(current->type))
		return (check_redir(current));
	return (1);
}

int	validator(t_token	*tokens)
{
	t_token	*current;
	t_token	*prev;

	if (!tokens)
		return (0);
	current = tokens;
	prev = NULL;
	while (current)
	{
		if (!check_token(prev, current))
			return (0);
		prev = current;
		current = current->next;
	}
	return (1);
}
