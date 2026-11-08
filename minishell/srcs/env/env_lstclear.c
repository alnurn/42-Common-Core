/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:58:10 by anurmach          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_lst_recursive(t_env *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	env_lst_recursive(lst->next, del);
	env_lstdelone(lst, del);
}

void	env_lstclear(t_env **lst, void (*del)(void *))
{
	if (!lst || !(*lst) || !del)
		return ;
	env_lst_recursive(*lst, del);
	*lst = NULL;
}
