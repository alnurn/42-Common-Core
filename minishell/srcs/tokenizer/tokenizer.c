/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_token_to_list(t_token **list, char *str, int len,
				t_token_type type)
{
	char	*token;
	t_token	*newnode;

	if (!list || !str)
		return (0);
	token = ft_substr((const char *) str, 0, len);
	if (!token)
		return (0);
	newnode = tok_lstnew(token, type);
	if (!newnode)
		return (0);
	tok_lstadd_back(list, newnode);
	return (1);
}

static int	get_tokens2(t_token **list, char *str, int *index)
{
	int	len;

	if (!list || !str || !index)
		return (0);
	len = is_word(&str[*index]);
	if (len)
	{
		if (!add_token_to_list(list, &str[*index], len, TOK_WORD))
			return (0);
		*index += len;
	}
	return (1);
}

t_token	*get_tokens(char *str)
{
	int		i;
	int		len;
	t_token	*list;

	if (!str)
		return (NULL);
	i = 0;
	list = NULL;
	while (str[i])
	{
		i += skip_spaces(&str[i]);
		len = is_operator(&str[i]);
		if (len)
		{
			if (!add_token_to_list(&list, &str[i], len, -1))
				return (tok_lstclear(&list, free), NULL);
			i += len;
		}
		if (!get_tokens2(&list, str, &i))
			return (tok_lstclear(&list, free), NULL);
	}
	put_operator_types(list);
	return (list);
}
