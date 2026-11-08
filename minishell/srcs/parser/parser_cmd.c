/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redir	*redir_new(t_token *tokens)
{
	t_redir	*node;

	node = (t_redir *) malloc(sizeof(t_redir));
	if (!node)
		return (NULL);
	node->type = tokens->type;
	node->file = ft_strdup(tokens->next->token);
	node->quoted = is_quoted(tokens->next->token);
	node->fd = parse_target_fd(tokens->type, tokens->token);
	node->next = NULL;
	if (!node->file)
		return (free(node), NULL);
	return (node);
}

static void	redir_lstadd_back(t_redir **lst, t_redir *new_node)
{
	t_redir	*last;

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

static int	build_redir(t_cmd *cmd, t_token **tokens)
{
	t_redir	*node;

	node = redir_new(*tokens);
	if (!node)
		return (0);
	redir_lstadd_back(&cmd->redirs, node);
	*tokens = (*tokens)->next->next;
	return (1);
}

static int	build_arg(t_list **args, t_token **tokens)
{
	char	*copy;
	t_list	*node;

	copy = ft_strdup((*tokens)->token);
	if (!copy)
		return (0);
	node = ft_lstnew(copy);
	if (!node)
		return (ft_lstclear(args, free), free(copy), 0);
	ft_lstadd_back(args, node);
	*tokens = (*tokens)->next;
	return (1);
}

t_cmd	*build_cmd(t_token **tokens)
{
	t_cmd	*cmd;
	t_list	*args;
	int		flag;

	cmd = cmd_lstnew();
	if (!cmd)
		return (NULL);
	args = NULL;
	flag = 1;
	while (flag && *tokens && (*tokens)->type != TOK_PIPE)
	{
		if ((*tokens)->type != TOK_WORD)
			flag = build_redir(cmd, tokens);
		else
			flag = build_arg(&args, tokens);
	}
	if (!flag)
		return (ft_lstclear(&args, free), free_pipeline(&cmd), NULL);
	cmd->raw_args = lst_to_charr(args);
	return (cmd);
}
