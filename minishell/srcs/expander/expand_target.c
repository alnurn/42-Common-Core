/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_ambiguous(char *raw)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(raw, STDERR_FILENO);
	ft_putstr_fd(": ambiguous redirect\n", STDERR_FILENO);
}

char	*expand_target(char *raw, t_shell *shell)
{
	char	**words;
	t_list	*temp;
	char	*result;

	temp = expand_word(raw, shell);
	words = lst_to_charr(temp);
	if (!words)
		return (NULL);
	if (!words[0] || words[1])
	{
		print_ambiguous(raw);
		free_charr(words);
		return (NULL);
	}
	result = ft_strdup(words[0]);
	free_charr(words);
	return (result);
}
