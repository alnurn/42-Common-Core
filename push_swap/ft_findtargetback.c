/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findtargetback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:35:30 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/30 20:35:34 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_findnodeback(t_list	**src, t_list	**dst)
{
	t_list	*ptr_dst;
	int		flag_dst;

	if (!src || !(*src) || !dst || !(*dst))
		return ;
	flag_dst = 0;
	ptr_dst = *dst;
	while (!(flag_dst && ptr_dst == *dst))
	{
		flag_dst = 1;
		if ((*src)->content > ptr_dst->content
			&& (*src)->content < ptr_dst->next->content)
		{
			(*src)->target = ptr_dst->next;
			return ;
		}
		ptr_dst = ptr_dst->next;
	}
}

void	ft_findtargetback(t_list	**src, t_list	**dst)
{
	t_list	*ptr;
	int		flag;
	t_list	*min;
	t_list	*max;

	if (!src || !(*src) || !dst || !(*dst))
		return ;
	flag = 0;
	ptr = *src;
	min = ft_minode(dst);
	max = ft_maxnode(dst);
	while (!(flag && ptr == *src))
	{
		flag = 1;
		if (ptr->content < min->content)
			ptr->target = min;
		else if (ptr->content > max->content)
			ptr->target = min;
		else
			ft_findnodeback(&ptr, dst);
		ptr = ptr->next;
	}
}
