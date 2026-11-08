/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*inside_quotes(char *raw, int *i)
{
	char	quote;
	int		start;
	char	*res;

	quote = raw[*i];
	(*i)++;
	start = *i;
	while (raw[*i] && raw[*i] != quote)
		(*i)++;
	res = ft_substr(raw, start, *i - start);
	if (raw[*i])
		(*i)++;
	return (res);
}

static char	*before_quote(char *raw, int *i)
{
	int	start;

	start = *i;
	while (raw[*i] && raw[*i] != SINGLE_QUOTE && raw[*i] != DOUBLE_QUOTE)
		(*i)++;
	return (ft_substr(raw, start, *i - start));
}

char	*strip_quotes(char *raw)
{
	char	*result;
	char	*fragment;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (result && raw[i])
	{
		if (raw[i] == SINGLE_QUOTE || raw[i] == DOUBLE_QUOTE)
			fragment = inside_quotes(raw, &i);
		else
			fragment = before_quote(raw, &i);
		result = join_free(result, fragment);
	}
	return (result);
}
