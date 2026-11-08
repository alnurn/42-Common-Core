/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*       mgumberi <mgumberi@student.42prague.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 17:57:35 by mgumberi          #+#    #+#             */
/*   Updated: 2026/08/28 00:00:00 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	tok_lst_recursive(t_token *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	tok_lst_recursive(lst->next, del);
	tok_lstdelone(lst, del);
}

void	tok_lstclear(t_token **lst, void (*del)(void *))
{
	if (!lst || !(*lst) || !del)
		return ;
	tok_lst_recursive(*lst, del);
	*lst = NULL;
}
