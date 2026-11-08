/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:51:39 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/15 20:55:20 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list	**lst, t_list	*new)
{
	if (!new || !lst)
		return ;
	if (*lst)
	{
		new->next = (*lst);
		(*lst)->previous->next = new;
		new->previous = (*lst)->previous;
		(*lst)->previous = new;
	}
	(*lst) = new;
}
