/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:51:19 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/15 15:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*lastnode;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		lastnode = ft_lstlast(*lst);
		if (lastnode == (*lst))
		{
			lastnode->next = new;
			new->previous = lastnode;
			lastnode->previous = new;
			new->next = lastnode;
		}
		else
		{
			lastnode->next = new;
			new->previous = lastnode;
			new->next = *lst;
			(*lst)->previous = new;
		}
	}
	else
		*lst = new;
}
