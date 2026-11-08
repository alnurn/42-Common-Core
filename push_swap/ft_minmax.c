/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:42:04 by anurmach          #+#    #+#             */
/*   Updated: 2025/12/06 21:42:05 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_minode(t_list	**stack)
{
	t_list	*min;
	t_list	*ptr;
	t_list	*head;

	if (!stack || !(*stack))
		return (NULL);
	ptr = *stack;
	head = *stack;
	min = *stack;
	while (ptr->next != head)
	{
		if (ptr->next->content < min->content)
			min = ptr->next;
		ptr = ptr->next;
	}
	return (min);
}

t_list	*ft_maxnode(t_list	**stack)
{
	t_list	*max;
	t_list	*ptr;
	t_list	*head;

	if (!stack || !(*stack))
		return (NULL);
	ptr = *stack;
	head = *stack;
	max = *stack;
	while (ptr->next != head)
	{
		if (ptr->next->content > max->content)
			max = ptr->next;
		ptr = ptr->next;
	}
	return (max);
}
