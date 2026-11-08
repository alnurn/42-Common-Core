/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "tokenizer.h"
# include "utils.h"

typedef struct s_redir
{
	t_token_type	type;
	char			*file;
	int				quoted;
	int				fd;
	struct s_redir	*next;
}	t_redir;

typedef struct s_cmd
{
	char			**raw_args;
	char			**args;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

/*parser.c*/
t_cmd	*parse_tokens(t_token *tokens);

/*parser_cmd.c*/
t_cmd	*build_cmd(t_token **tokens);

/*parser_utils.c*/
t_cmd	*cmd_lstnew(void);
void	cmd_lstadd_back(t_cmd **lst, t_cmd *new_node);
int		is_quoted(char *str);
int		parse_target_fd(t_token_type type, char *op_text);

/*parser_free.c*/
void	free_pipeline(t_cmd **pipeline);

#endif
