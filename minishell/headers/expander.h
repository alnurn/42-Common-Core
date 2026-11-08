/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "parser.h"
# include "shell.h"

typedef struct s_wbuf
{
	t_list	*words;
	char	*current;
}	t_wbuf;

/*expander.c*/
int		expand_pipeline(t_cmd *pipeline, t_shell *shell);

/*expand_word.c*/
t_list	*expand_word(char *raw, t_shell *shell);
void	join_to_current(t_wbuf *buf, char *str);

/*expand_split.c*/
void	add_current(t_wbuf *buf);
void	append_splittable(t_wbuf *buf, char *val);

/*expand_quotes.c*/
char	*extract_single_quote(char *raw, int *i);
char	*extract_double_quote(char *raw, int *i, t_shell *shell);
char	*join_free(char *base, char *addition);

/*expand_var.c*/
char	*expand_dollar(char *raw, int *i, t_shell *shell);

/*expand_target.c*/
char	*expand_target(char *raw, t_shell *shell);

/*expand_heredoc.c*/
char	*strip_quotes(char *raw);

/*expand_heredoc_line.c*/
char	*expand_heredoc_line(char *line, t_shell *shell);

#endif
