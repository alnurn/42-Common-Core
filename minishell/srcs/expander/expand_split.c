/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_current(t_wbuf *buf)
{
	t_list	*node;

	if (!buf->current)
		return ;
	node = ft_lstnew(buf->current);
	if (node)
		ft_lstadd_back(&buf->words, node);
	buf->current = NULL;
}

static char	*extract_content(char *val, int *i)
{
	int	start;

	while (val[*i] == ' ' || val[*i] == '\t')
		(*i)++;
	start = *i;
	while (val[*i] && val[*i] != ' ' && val[*i] != '\t')
		(*i)++;
	return (ft_substr(val, start, *i - start));
}

void	append_splittable(t_wbuf *buf, char *val)
{
	int		i;
	char	*fragment;

	i = 0;
	while (val[i])
	{
		if (val[i] == ' ' || val[i] == '\t')
		{
			add_current(buf);
			i++;
		}
		else
		{
			fragment = extract_content(val, &i);
			if (buf->current)
			{
				join_to_current(buf, fragment);
				free(fragment);
			}
			else
				buf->current = fragment;
		}
	}
	free(val);
}
