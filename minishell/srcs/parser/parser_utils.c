/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*cmd_lstnew(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *) malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->raw_args = NULL;
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	cmd_lstadd_back(t_cmd **lst, t_cmd *new_node)
{
	t_cmd	*last;

	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

int	is_quoted(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE)
			return (1);
		i++;
	}
	return (0);
}

int	parse_target_fd(t_token_type type, char *op_text)
{
	if (op_text[0] >= '0' && op_text[0] <= '9')
		return (ft_atoi(op_text));
	if (type == TOK_REDIR_OUTPUT || type == TOK_REDIR_APPEND)
		return (STDOUT_FILENO);
	return (STDIN_FILENO);
}
