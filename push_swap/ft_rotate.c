/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:49:08 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 19:49:14 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list	**stack)
{
	if (!stack || !(*stack))
		return ;
	if ((*stack) != (*stack)->next)
		(*stack) = (*stack)->next;
}

void	ft_ra(t_stacks	*stacks)
{
	if (!stacks || !stacks->stack_a)
		return ;
	if (stacks->size_a < 2)
		return ;
	ft_rotate(&(stacks->stack_a));
	if (stacks->print_op == true)
		ft_printf("ra\n");
}

void	ft_rb(t_stacks	*stacks)
{
	if (!stacks || !stacks->stack_b)
		return ;
	if (stacks->size_b < 2)
		return ;
	ft_rotate(&(stacks->stack_b));
	if (stacks->print_op == true)
		ft_printf("rb\n");
}

void	ft_rr(t_stacks	*stacks)
{
	if (!stacks || !(stacks->stack_a) || !(stacks->stack_b))
		return ;
	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	ft_rotate(&(stacks->stack_a));
	ft_rotate(&(stacks->stack_b));
	if (stacks->print_op == true)
		ft_printf("rr\n");
}
