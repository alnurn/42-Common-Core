/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*parse_tokens(t_token *tokens)
{
	t_cmd	*pipeline;
	t_cmd	*cmd;

	if (!tokens)
		return (NULL);
	pipeline = NULL;
	while (tokens)
	{
		cmd = build_cmd(&tokens);
		if (!cmd)
			return (free_pipeline(&pipeline), NULL);
		cmd_lstadd_back(&pipeline, cmd);
		if (tokens && tokens->type == TOK_PIPE)
			tokens = tokens->next;
	}
	return (pipeline);
}
