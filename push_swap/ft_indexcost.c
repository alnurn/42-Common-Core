/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexcost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:19:48 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/29 18:19:51 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_topcost(t_list	**stack, int size)
{
	t_list	*ptr;
	int		flag;

	if (!stack || !(*stack))
		return ;
	flag = 0;
	ptr = *stack;
	while (!(flag && ptr == *stack))
	{
		flag = 1;
		if (ptr->index <= size / 2)
			ptr->nodecost = ptr->index;
		else
			ptr->nodecost = size - ptr->index;
		ptr = ptr->next;
	}
}

void	ft_index(t_list	**stack)
{
	t_list	*ptr;
	int		i;
	int		flag;

	if (!stack || !(*stack))
		return ;
	i = 0;
	flag = 0;
	ptr = *stack;
	while (!(flag && ptr == *stack))
	{
		flag = 1;
		ptr->index = i;
		ptr = ptr->next;
		i++;
	}
}

void	ft_indexation(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->stack_a)
		ft_index(&(stacks->stack_a));
	if (stacks->stack_b)
		ft_index(&(stacks->stack_b));
}

void	ft_costcalculate(t_list	**src, int srcsize, int dstsize)
{
	int		flag;
	t_list	*ptr;

	if (!src || !(*src))
		return ;
	flag = 0;
	ptr = *src;
	while (!(flag && ptr == *src))
	{
		flag = 1;
		if ((ptr->index <= srcsize / 2 && ptr->target->index <= dstsize / 2)
			|| (ptr->index > srcsize / 2 && ptr->target->index > dstsize / 2))
		{
			if (ptr->nodecost > ptr->target->nodecost)
				ptr->generalcost = ptr->nodecost;
			else
				ptr->generalcost = ptr->target->nodecost;
		}
		else
			ptr->generalcost = ptr->nodecost + ptr->target->nodecost;
		ptr = ptr->next;
	}
}

t_list	*ft_findmincost(t_list	**stack)
{
	t_list	*ptr;
	t_list	*ptrmincost;
	int		flag;
	int		temp;

	if (!stack || !(*stack))
		return (NULL);
	flag = 0;
	ptr = *stack;
	ptrmincost = *stack;
	temp = ptr->generalcost;
	while (!(flag && ptr == *stack))
	{
		flag = 1;
		if (temp > ptr->generalcost)
		{
			temp = ptr->generalcost;
			ptrmincost = ptr;
		}
		ptr = ptr->next;
	}
	return (ptrmincost);
}
