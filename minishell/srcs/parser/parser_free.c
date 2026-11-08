/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_redirs(t_redir *redirs)
{
	t_redir	*next;

	while (redirs)
	{
		next = redirs->next;
		free(redirs->file);
		free(redirs);
		redirs = next;
	}
}

static void	free_cmd(t_cmd *cmd)
{
	free_redirs(cmd->redirs);
	free_charr(cmd->raw_args);
	free_charr(cmd->args);
	free(cmd);
}

void	free_pipeline(t_cmd **pipeline)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!pipeline || !*pipeline)
		return ;
	current = *pipeline;
	while (current)
	{
		next = current->next;
		free_cmd(current);
		current = next;
	}
	*pipeline = NULL;
}
