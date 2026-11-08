/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_spaces(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	is_operator(char *str)
{
	int	digits;

	if (!str)
		return (0);
	digits = count_digits(str);
	if (str[digits] != REDIR_INPUT && str[digits] != REDIR_OUTPUT)
		digits = 0;
	if (!ft_strncmp((const char *) &str[digits], HEREDOC, 2))
		return (digits + 2);
	if (!ft_strncmp((const char *) &str[digits], REDIR_APPEND, 2))
		return (digits + 2);
	if (!ft_strncmp((const char *) str, AND, 2))
		return (2);
	if (!ft_strncmp((const char *) str, OR, 2))
		return (2);
	if (str[digits] == REDIR_INPUT || str[digits] == REDIR_OUTPUT)
		return (digits + 1);
	if (str[0] == PIPE || str[0] == PARENTHESIS_OPEN
		|| str[0] == PARENTHESIS_CLOSE)
		return (1);
	return (0);
}

int	is_word(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && !(str[i] == ' ' || str[i] == '\t')
		&& !is_operator(&str[i]))
	{
		if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE)
			i += find_end_quotes(&str[i], str[i]);
		if (str[i])
			i++;
	}
	return (i);
}
