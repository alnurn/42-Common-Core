/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_add(t_env **envp, const char *key, const char *value)
{
	t_env	*newnode;
	char	*dup_key;
	char	*dup_value;

	dup_key = ft_strdup(key);
	dup_value = ft_strdup(value);
	if (!dup_key || !dup_value)
		return (free(dup_key), free(dup_value), 0);
	newnode = env_lstnew(dup_key, dup_value);
	if (!newnode)
		return (free(dup_key), free(dup_value), 0);
	env_lstadd_back(envp, newnode);
	return (1);
}

int	env_set(t_env **envp, const char *key, const char *value)
{
	t_env	*node;
	char	*new_value;

	node = get_env(key, *envp);
	if (!node)
		return (env_add(envp, key, value));
	new_value = ft_strdup(value);
	if (!new_value)
		return (0);
	free(node->content);
	node->content = new_value;
	return (1);
}

int	env_declare(t_env **envp, const char *key)
{
	t_env	*node;
	t_env	*newnode;
	char	*dup_key;

	node = get_env(key, *envp);
	if (node)
		return (1);
	dup_key = ft_strdup(key);
	if (!dup_key)
		return (0);
	newnode = env_lstnew(dup_key, NULL);
	if (!newnode)
		return (free(dup_key), 0);
	env_lstadd_back(envp, newnode);
	return (1);
}
