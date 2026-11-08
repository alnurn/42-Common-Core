/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:51:19 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/26 02:12:32 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*lastnode;

	if (!lst)
		return ;
	if (*lst)
	{
		lastnode = ft_lstlast(*lst);
		lastnode->next = new;
	}
	else
		*lst = new;
}
