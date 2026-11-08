/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movetotopback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:45:36 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/30 20:45:37 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moveb_back(t_stacks	*stacks, int nodeindex, int i)
{
	if (!stacks || !stacks->stack_b)
		return ;
	if (nodeindex <= stacks->size_b / 2)
	{
		while (i--)
			ft_rb(stacks);
	}
	else
	{
		while (i--)
			ft_rrb(stacks);
	}
}

void	ft_movea_back(t_stacks	*stacks, int nodeindex, int i)
{
	if (!stacks || !stacks->stack_a)
		return ;
	if (nodeindex <= stacks->size_a / 2)
	{
		while (i--)
			ft_ra(stacks);
	}
	else
	{
		while (i--)
			ft_rra(stacks);
	}
}

void	ft_move_back(t_stacks	*stacks, t_list	*mincost, int n)
{
	if (!stacks || !stacks->stack_a || !stacks->stack_b || !mincost)
		return ;
	if (mincost->index <= stacks->size_b / 2
		&& mincost->target->index <= stacks->size_a / 2)
	{
		while (n--)
			ft_rr(stacks);
	}
	else if (mincost->index > stacks->size_b / 2
		&& mincost->target->index > stacks->size_a / 2)
	{
		while (n--)
			ft_rrr(stacks);
	}
}

void	ft_moveboth_back(t_stacks	*stacks, t_list	*mincost)
{
	int	n;
	int	i;

	if (!stacks || !stacks->stack_a || !stacks->stack_b || !mincost)
		return ;
	if (mincost->nodecost < mincost->target->nodecost)
	{
		n = mincost->nodecost;
		ft_move_back(stacks, mincost, n);
		i = mincost->target->nodecost - mincost->nodecost;
		ft_movea_back(stacks, mincost->index, i);
	}
	else
	{
		n = mincost->target->nodecost;
		ft_move_back(stacks, mincost, n);
		i = mincost->nodecost - mincost->target->nodecost;
		ft_moveb_back(stacks, mincost->target->index, i);
	}
}

void	ft_movetotopback(t_stacks	*stacks)
{
	t_list	*mincost;

	mincost = ft_findmincost(&(stacks->stack_b));
	if (!stacks || !stacks->stack_a || !stacks->stack_b || !mincost)
		return ;
	if (mincost->nodecost + mincost->target->nodecost == mincost->generalcost)
	{
		ft_moveb_back(stacks, mincost->index, mincost->nodecost);
		ft_movea_back(stacks, mincost->target->index,
			mincost->target->nodecost);
	}
	else
		ft_moveboth_back(stacks, mincost);
}
