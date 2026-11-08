/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:58:10 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/25 15:03:52 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(t_list	*lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	ft_recursive(lst->next, del);
	ft_lstdelone(lst, del);
}

void	ft_lstclear(t_list	**lst, void (*del)(void	*))
{
	if (!lst || !(*lst) || !del)
		return ;
	ft_recursive(*lst, del);
	*lst = NULL;
}
