/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	var_name_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && (ft_isalnum((unsigned char) str[i]) || str[i] == '_'))
		i++;
	return (i);
}

char	*expand_dollar(char *raw, int *i, t_shell *shell)
{
	size_t	len;
	char	*key;
	char	*value;
	t_env	*node;

	(*i)++;
	if (raw[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(shell->exit_status));
	}
	len = var_name_len(&raw[*i]);
	if (len == 0)
		return (ft_strdup("$"));
	key = ft_substr(&raw[*i], 0, len);
	*i += len;
	if (!key)
		return (NULL);
	node = get_env(key, shell->env);
	if (!node || !node->content)
		return (free(key), ft_strdup(""));
	value = ft_strdup(node->content);
	return (free(key), value);
}
