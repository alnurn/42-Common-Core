/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:56:14 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 20:56:16 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list	**src, t_list	**dst)
{
	t_list	*node;
	t_list	*last;

	if (!src || !dst || !(*src))
		return ;
	node = *src;
	if (*src != (*src)->next)
	{
		last = ft_lstlast(*src);
		*src = (*src)->next;
		last->next = *src;
		(*src)->previous = last;
		node->next = node;
		node->previous = node;
	}
	else
		*src = NULL;
	ft_lstadd_front(dst, node);
}

void	ft_pa(t_stacks	*stacks)
{
	if (!stacks || !(stacks->stack_b))
		return ;
	ft_push(&(stacks->stack_b), &(stacks->stack_a));
	stacks->size_a += 1;
	stacks->size_b -= 1;
	if (stacks->print_op == true)
		ft_printf("pa\n");
}

void	ft_pb(t_stacks	*stacks)
{
	if (!stacks || !(stacks->stack_a))
		return ;
	ft_push(&(stacks->stack_a), &(stacks->stack_b));
	stacks->size_a -= 1;
	stacks->size_b += 1;
	if (stacks->print_op == true)
		ft_printf("pb\n");
}
