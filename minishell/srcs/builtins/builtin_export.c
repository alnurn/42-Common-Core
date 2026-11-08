/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_invalid_error(char *arg)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

static int	split_kv(char *arg, char **key, char **value)
{
	char	*eq;

	eq = ft_strchr(arg, '=');
	if (!eq)
	{
		*key = ft_strdup(arg);
		*value = NULL;
		return (*key != NULL);
	}
	*key = ft_substr(arg, 0, eq - arg);
	*value = ft_strdup(eq + 1);
	return (*key && *value);
}

static int	export_one(char *arg, t_shell *shell)
{
	char	*key;
	char	*value;
	int		ok;

	if (!is_valid_identifier(arg))
		return (export_invalid_error(arg), 0);
	if (!split_kv(arg, &key, &value))
		return (free(key), free(value), 0);
	if (value)
		ok = env_set(&shell->env, key, value);
	else
		ok = env_declare(&shell->env, key);
	return (free(key), free(value), ok);
}

int	builtin_export(char **args, t_shell *shell)
{
	int	i;
	int	status;

	if (!args[1])
		return (export_no_args(shell));
	i = 1;
	status = 0;
	while (args[i])
	{
		if (!export_one(args[i], shell))
			status = 1;
		i++;
	}
	return (status);
}
