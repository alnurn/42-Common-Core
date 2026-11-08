/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findtarget.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:51:41 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/29 21:51:45 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_findnode(t_list	*src, t_list	*dst)
{
	t_list	*ptr;
	int		flag;

	if (!src || !dst)
		return ;
	flag = 0;
	ptr = dst;
	while (!(flag && ptr == dst))
	{
		flag = 1;
		if (src->content < ptr->content
			&& src->content > ptr->next->content)
		{
			src->target = ptr->next;
			return ;
		}
		ptr = ptr->next;
	}
}

void	ft_findtarget(t_list	*src, t_list	*dst)
{
	t_list	*ptr;
	int		flag;
	t_list	*min;
	t_list	*max;

	if (!src || !dst)
		return ;
	flag = 0;
	ptr = src;
	min = ft_minode(&dst);
	max = ft_maxnode(&dst);
	while (!(flag && ptr == src))
	{
		flag = 1;
		if (ptr->content < min->content)
			ptr->target = max;
		else if (ptr->content > max->content)
			ptr->target = max;
		else
			ft_findnode(ptr, dst);
		ptr = ptr->next;
	}
}
