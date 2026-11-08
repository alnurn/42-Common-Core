/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	expand_cmd_args(t_cmd *cmd, t_shell *shell)
{
	t_list	*all;
	t_list	*part;
	int		i;

	all = NULL;
	i = 0;
	while (cmd->raw_args && cmd->raw_args[i])
	{
		part = expand_word(cmd->raw_args[i], shell);
		if (part)
			ft_lstadd_back(&all, part);
		i++;
	}
	cmd->args = lst_to_charr(all);
	if (cmd->args == NULL)
		return (0);
	else
		return (1);
}

static int	expand_cmd_redirs(t_cmd *cmd, t_shell *shell)
{
	t_redir	*redir;
	char	*expanded;

	redir = cmd->redirs;
	while (redir)
	{
		if (redir->type == TOK_HEREDOC)
			expanded = strip_quotes(redir->file);
		else
			expanded = expand_target(redir->file, shell);
		if (!expanded)
			return (0);
		free(redir->file);
		redir->file = expanded;
		redir = redir->next;
	}
	return (1);
}

int	expand_pipeline(t_cmd *pipeline, t_shell *shell)
{
	while (pipeline)
	{
		if (!expand_cmd_args(pipeline, shell))
			return (0);
		if (!expand_cmd_redirs(pipeline, shell))
			return (0);
		pipeline = pipeline->next;
	}
	return (1);
}
