/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstremove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 00:00:00 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_lstremove(t_env **lst, const char *key)
{
	t_env	*node;

	node = get_env(key, *lst);
	if (!node)
		return ;
	if (node->previous)
		node->previous->next = node->next;
	else
		*lst = node->next;
	if (node->next)
		node->next->previous = node->previous;
	env_lstdelone(node, free);
}
