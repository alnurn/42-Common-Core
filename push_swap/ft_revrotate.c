/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:31:28 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 20:31:30 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revrotate(t_list	**stack)
{
	if (!stack || !(*stack))
		return ;
	if ((*stack) != (*stack)->previous)
		(*stack) = (*stack)->previous;
}

void	ft_rra(t_stacks	*stacks)
{
	if (!stacks || !stacks->stack_a)
		return ;
	if (stacks->size_a < 2)
		return ;
	ft_revrotate(&(stacks->stack_a));
	if (stacks->print_op == true)
		ft_printf("rra\n");
}

void	ft_rrb(t_stacks	*stacks)
{
	if (!stacks || !stacks->stack_b)
		return ;
	if (stacks->size_b < 2)
		return ;
	ft_revrotate(&(stacks->stack_b));
	if (stacks->print_op == true)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stacks	*stacks)
{
	if (!stacks || !(stacks->stack_a) || !(stacks->stack_b))
		return ;
	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	ft_revrotate(&(stacks->stack_a));
	ft_revrotate(&(stacks->stack_b));
	if (stacks->print_op == true)
		ft_printf("rrr\n");
}
