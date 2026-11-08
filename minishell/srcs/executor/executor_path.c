/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_regular_file(char *path)
{
	struct stat	st;

	if (stat(path, &st) != 0)
		return (0);
	return (S_ISREG(st.st_mode));
}

static char	*try_path(char *dir, char *name)
{
	char	*prefix;
	char	*full;

	prefix = ft_strjoin(dir, "/");
	if (!prefix)
		return (NULL);
	full = ft_strjoin(prefix, name);
	free(prefix);
	if (!full)
		return (NULL);
	if (access(full, X_OK) == 0 && is_regular_file(full))
		return (full);
	return (free(full), NULL);
}

static char	*search_path_dirs(char *name, char *path_value)
{
	char	**dirs;
	char	*found;
	int		i;

	dirs = ft_split(path_value, ':');
	if (!dirs)
		return (NULL);
	found = NULL;
	i = 0;
	while (dirs[i] && !found)
	{
		found = try_path(dirs[i], name);
		i++;
	}
	return (free_charr(dirs), found);
}

char	*find_executable(char *name, t_env *env)
{
	t_env	*path_var;

	if (!name || !name[0])
		return (NULL);
	if (ft_strchr(name, '/'))
	{
		if (access(name, X_OK) == 0 && is_regular_file(name))
			return (ft_strdup(name));
		return (NULL);
	}
	path_var = get_env("PATH", env);
	if (!path_var)
		return (NULL);
	return (search_path_dirs(name, path_var->content));
}
