/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*extract_normal(char *raw, int *i)
{
	int	start;

	start = *i;
	while (raw[*i] && raw[*i] != SINGLE_QUOTE && raw[*i] != DOUBLE_QUOTE
		&& raw[*i] != DOLLAR)
		(*i)++;
	return (ft_substr(raw, start, *i - start));
}

static char	*expand_fragment(char *raw, int *i, t_shell *shell, t_wbuf *buf)
{
	if (raw[*i] == SINGLE_QUOTE)
		return (extract_single_quote(raw, i));
	if (raw[*i] == DOUBLE_QUOTE)
		return (extract_double_quote(raw, i, shell));
	if (raw[*i] == DOLLAR)
	{
		append_splittable(buf, expand_dollar(raw, i, shell));
		return (NULL);
	}
	return (extract_normal(raw, i));
}

void	join_to_current(t_wbuf *buf, char *str)
{
	char	*joined;

	if (!buf->current)
		buf->current = ft_strdup("");
	joined = ft_strjoin(buf->current, str);
	free(buf->current);
	buf->current = joined;
}

t_list	*expand_word(char *raw, t_shell *shell)
{
	t_wbuf	buf;
	int		i;
	char	*fragment;

	buf.words = NULL;
	buf.current = NULL;
	i = 0;
	while (raw[i])
	{
		fragment = expand_fragment(raw, &i, shell, &buf);
		if (fragment)
		{
			join_to_current(&buf, fragment);
			free(fragment);
		}
	}
	add_current(&buf);
	return (buf.words);
}
