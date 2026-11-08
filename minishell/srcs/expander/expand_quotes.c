/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*extract_single_quote(char *raw, int *i)
{
	int		start;
	char	*res;

	(*i)++;
	start = *i;
	while (raw[*i] && raw[*i] != SINGLE_QUOTE)
		(*i)++;
	res = ft_substr(raw, start, *i - start);
	if (raw[*i])
		(*i)++;
	return (res);
}

char	*join_free(char *base, char *addition)
{
	char	*joined;

	if (!base || !addition)
		return (free(base), free(addition), NULL);
	joined = ft_strjoin(base, addition);
	free(base);
	free(addition);
	return (joined);
}

char	*extract_double_quote(char *raw, int *i, t_shell *shell)
{
	char	*result;
	char	*fragment;
	int		start;

	result = ft_strdup("");
	(*i)++;
	while (result && raw[*i] && raw[*i] != DOUBLE_QUOTE)
	{
		if (raw[*i] == DOLLAR)
			fragment = expand_dollar(raw, i, shell);
		else
		{
			start = *i;
			while (raw[*i] && raw[*i] != DOUBLE_QUOTE && raw[*i] != DOLLAR)
				(*i)++;
			fragment = ft_substr(raw, start, *i - start);
		}
		result = join_free(result, fragment);
	}
	if (raw[*i])
		(*i)++;
	return (result);
}
