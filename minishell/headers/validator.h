/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 17:56:28 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

# include "../libft/libft.h"
# include "tokenizer.h"

# define ERR_UNCLOSED_QUOTES 1
# define ERR_UNEXPECTED_TOKEN 2
# define ERR_UNEXPECTED_NEWLINE 3

/*validator.c*/
int		validator(t_token *tokens);
int		find_end_quotes(char *str, char quote);

/*syntax_checks.c*/
int		is_unsupported(t_token_type type);
int		is_redir(t_token_type type);
int		check_pipe(t_token	*prev, t_token	*current);
int		check_redir(t_token	*current);
void	print_syntax_error(int errorcode, char	*str);

#endif
