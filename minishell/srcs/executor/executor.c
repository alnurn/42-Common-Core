/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pipeline(t_cmd *pipeline, t_shell *shell)
{
	if (!pipeline)
		return (shell->exit_status);
	shell->current_pipeline = pipeline;
	if (!run_heredocs(pipeline, shell))
		return (shell->current_pipeline = NULL,
			shell->exit_status = 128 + g_signal);
	if (!pipeline->next)
		shell->exit_status = execute_single(pipeline, shell);
	else
		shell->exit_status = execute_multi(pipeline, shell);
	shell->current_pipeline = NULL;
	return (shell->exit_status);
}
