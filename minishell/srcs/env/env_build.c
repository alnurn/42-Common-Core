/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_env(t_env *envp)
{
	int	count;

	count = 0;
	while (envp)
	{
		count++;
		envp = envp->next;
	}
	return (count);
}

static char	*make_kv_string(char *key, char *content)
{
	char	*tmp;
	char	*result;

	tmp = ft_strjoin(key, "=");
	if (!tmp)
		return (NULL);
	result = ft_strjoin(tmp, content);
	free(tmp);
	return (result);
}

char	**build_envp(t_env *envp)
{
	char	**arr;
	int		count;
	int		i;

	count = count_env(envp);
	arr = (char **) malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (envp)
	{
		if (envp->content)
		{
			arr[i] = make_kv_string(envp->key, envp->content);
			if (!arr[i])
				return (free_charr(arr), NULL);
			i++;
		}
		envp = envp->next;
	}
	arr[i] = NULL;
	return (arr);
}
