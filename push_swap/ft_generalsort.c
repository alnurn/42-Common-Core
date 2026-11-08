/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generalsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:10:51 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/18 14:10:53 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pushtob(t_stacks	*stacks)
{
	if (!stacks || !stacks->stack_a)
		return ;
	ft_pb(stacks);
	while (stacks->size_a > 3 && !(ft_ifhiddensorted(&(stacks->stack_a))))
	{
		ft_indexation(stacks);
		ft_topcost(&(stacks->stack_a), stacks->size_a);
		ft_topcost(&(stacks->stack_b), stacks->size_b);
		ft_findtarget(stacks->stack_a, stacks->stack_b);
		ft_costcalculate(&(stacks->stack_a), stacks->size_a, stacks->size_b);
		ft_movetotop(stacks);
		ft_pb(stacks);
	}
	ft_twothreesort(stacks);
}

void	ft_pushtoa(t_stacks	*stacks)
{
	if (!stacks || !stacks->stack_b)
		return ;
	while (stacks->stack_b)
	{
		ft_indexation(stacks);
		ft_topcost(&(stacks->stack_b), stacks->size_b);
		ft_topcost(&(stacks->stack_a), stacks->size_a);
		ft_findtargetback(&(stacks->stack_b), &(stacks->stack_a));
		ft_costcalculate(&(stacks->stack_b), stacks->size_b, stacks->size_a);
		ft_movetotopback(stacks);
		ft_pa(stacks);
	}
	ft_indexation(stacks);
	ft_topcost(&(stacks->stack_a), stacks->size_a);
	ft_finalsort(stacks, ft_ifhiddensorted(&(stacks->stack_a)));
}

void	ft_generalsort(t_stacks *stacks)
{
	t_list	*min;

	if (!stacks || !stacks->stack_a)
		return ;
	if (ft_ifsorted(&(stacks->stack_a)))
		return ;
	if (stacks->size_a <= 3)
	{
		ft_twothreesort(stacks);
		return ;
	}
	ft_indexation(stacks);
	ft_topcost(&(stacks->stack_a), stacks->size_a);
	min = ft_ifhiddensorted(&(stacks->stack_a));
	if (min)
		ft_finalsort(stacks, min);
	else
	{
		ft_pushtob(stacks);
		ft_pushtoa(stacks);
	}
}
