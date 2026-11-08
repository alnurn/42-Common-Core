/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*chunk_until_dollar(char *line, int *i)
{
	int	start;

	start = *i;
	while (line[*i] && line[*i] != DOLLAR)
		(*i)++;
	return (ft_substr(line, start, *i - start));
}

char	*expand_heredoc_line(char *line, t_shell *shell)
{
	char	*result;
	char	*piece;
	int		i;

	result = ft_strdup("");
	i = 0;
	while (result && line[i])
	{
		if (line[i] == DOLLAR)
			piece = expand_dollar(line, &i, shell);
		else
			piece = chunk_until_dollar(line, &i);
		result = join_free(result, piece);
	}
	return (result);
}
