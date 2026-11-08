/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:51:19 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_lstadd_back(t_env **lst, t_env *new_node)
{
	t_env	*lastnode;

	if (!lst)
		return ;
	if (*lst)
	{
		lastnode = env_lstlast(*lst);
		lastnode->next = new_node;
		new_node->previous = lastnode;
	}
	else
		*lst = new_node;
}
