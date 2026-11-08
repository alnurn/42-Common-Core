/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:58:10 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/15 15:52:19 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(t_list	*lst, t_list	*head, int flag)
{
	if (lst == head && flag)
		return ;
	ft_recursive(lst->next, head, 1);
	ft_lstdelone(lst);
}

void	ft_lstclear(t_list	**lst)
{
	t_list	*head;

	if (!lst || !(*lst))
		return ;
	head = *lst;
	ft_recursive(*lst, head, 0);
	*lst = NULL;
}
