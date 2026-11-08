/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:56:28 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "../libft/libft.h"

# define SINGLE_QUOTE '\''
# define DOUBLE_QUOTE '\"'
# define REDIR_INPUT '<'
# define REDIR_OUTPUT '>'
# define HEREDOC "<<"
# define REDIR_APPEND ">>"
# define PIPE '|'
# define DOLLAR '$'
# define DOLLAR_QUESTION "$?"
# define AND "&&"
# define OR "||"
# define PARENTHESIS_OPEN '('
# define PARENTHESIS_CLOSE ')'
# define WILDCARD '*'

typedef enum e_token
{
	TOK_SINGLE_QUOTE,
	TOK_DOUBLE_QUOTE,
	TOK_REDIR_INPUT,
	TOK_REDIR_OUTPUT,
	TOK_HEREDOC,
	TOK_REDIR_APPEND,
	TOK_PIPE,
	TOK_DOLLAR,
	TOK_DOLLAR_QUESTION,
	TOK_AND,
	TOK_OR,
	TOK_PARENTHESIS_OPEN,
	TOK_PARENTHESIS_CLOSE,
	TOK_WILDCARD,
	TOK_WORD
}	t_token_type;

typedef struct s_token
{
	char			*token;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

/*tokenizer.c*/
t_token	*get_tokens(char *str);

/*tokenizer_utils.c*/
int		skip_spaces(char *str);
int		is_operator(char *str);
int		is_word(char *str);

/*tokenizer_utils2.c*/
void	put_operator_types(t_token *list);
int		count_digits(char *str);

/*tok_lstnew.c*/
t_token	*tok_lstnew(char *content, t_token_type type);
/*tok_lstlast.c*/
t_token	*tok_lstlast(t_token *lst);
/*tok_lstdelone.c*/
void	tok_lstdelone(t_token *lst, void (*del)(void *));
/*tok_lstclear.c*/
void	tok_lstclear(t_token **lst, void (*del)(void *));
/*tok_lstadd_back.c*/
void	tok_lstadd_back(t_token **lst, t_token *new_node);

#endif
