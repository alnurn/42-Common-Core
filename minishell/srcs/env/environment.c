/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:57:35 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_env(const char *key, t_env *envp)
{
	t_env	*current;
	int		len;

	if (!key || !envp)
		return (NULL);
	current = envp;
	len = ft_strlen(key);
	while (current)
	{
		if (ft_strncmp(key, current->key, len) == 0 && !current->key[len])
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	free_env(t_env **envp)
{
	if (!envp)
		return ;
	env_lstclear(envp, free);
}

static size_t	find_key_end(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

static char	*find_value(char *str, size_t key_end)
{
	if (str[key_end] == '=')
		return (ft_strdup(&str[key_end + 1]));
	return (ft_strdup(""));
}

t_env	*dup_env(char **envp)
{
	t_env	*list;
	t_env	*newnode;
	char	*key;
	char	*value;
	int		i;

	if (!envp)
		return (NULL);
	list = NULL;
	i = 0;
	while (envp[i])
	{
		key = ft_substr((const char *) envp[i], 0, find_key_end(envp[i]));
		value = find_value(envp[i], find_key_end(envp[i]));
		if (!key || !value)
			return (free(key), free(value), free_env(&list), NULL);
		newnode = env_lstnew(key, value);
		if (!newnode)
			return (free(key), free(value), free_env(&list), NULL);
		env_lstadd_back(&list, newnode);
		i++;
	}
	return (list);
}
