/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_export_entry(t_env *node)
{
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	ft_putstr_fd(node->key, STDOUT_FILENO);
	if (node->content)
	{
		ft_putstr_fd("=\"", STDOUT_FILENO);
		ft_putstr_fd(node->content, STDOUT_FILENO);
		ft_putstr_fd("\"", STDOUT_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}

int	export_no_args(t_shell *shell)
{
	t_env	**arr;
	t_env	*cur;
	int		count;
	int		i;

	count = 0;
	cur = shell->env;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	arr = collect_ptrs(shell->env, count);
	if (!arr)
		return (1);
	sort_ptrs(arr, count);
	i = 0;
	while (i < count)
		print_export_entry(arr[i++]);
	return (free(arr), 0);
}
