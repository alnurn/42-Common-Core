/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:44:08 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 18:44:18 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list	*stack)
{
	int	num;

	if (!stack)
		return ;
	if (stack != stack->next)
	{
		num = stack->content;
		stack->content = stack->next->content;
		stack->next->content = num;
	}
}

void	ft_sa(t_stacks	*stacks)
{
	if (!stacks || !stacks->stack_a)
		return ;
	if (stacks->size_a < 2)
		return ;
	ft_swap(stacks->stack_a);
	if (stacks->print_op == true)
		ft_printf("sa\n");
}

void	ft_sb(t_stacks	*stacks)
{
	if (!stacks || !stacks->stack_b)
		return ;
	if (stacks->size_b < 2)
		return ;
	ft_swap(stacks->stack_b);
	if (stacks->print_op == true)
		ft_printf("sb\n");
}

void	ft_ss(t_stacks	*stacks)
{
	if (!stacks || !(stacks->stack_a) || !(stacks->stack_b))
		return ;
	if (stacks->size_a < 2 || stacks->size_b < 2)
		return ;
	ft_swap(stacks->stack_a);
	ft_swap(stacks->stack_b);
	if (stacks->print_op == true)
		ft_printf("ss\n");
}
