/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twothreesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 21:41:43 by anurmach          #+#    #+#             */
/*   Updated: 2025/12/06 21:41:46 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_twonodesort(t_stacks	*stacks)
{
	if (!stacks || !stacks->stack_a)
		return ;
	ft_sa(stacks);
}

void	ft_threenodesort(t_stacks	*stacks)
{
	int	up;
	int	middle;
	int	bottom;

	if (!stacks || !stacks->stack_a)
		return ;
	up = stacks->stack_a->content;
	middle = stacks->stack_a->next->content;
	bottom = stacks->stack_a->next->next->content;
	if ((up > middle) && (up > bottom))
		ft_ra(stacks);
	else if ((middle > up) && (middle > bottom))
		ft_rra(stacks);
	if (!ft_ifsorted(&(stacks->stack_a)))
		ft_twonodesort(stacks);
}

void	ft_twothreesort(t_stacks	*stacks)
{
	if (!stacks || !(stacks->stack_a))
		return ;
	if (stacks->size_a == 2)
		ft_twonodesort(stacks);
	else if (stacks->size_a == 3)
		ft_threenodesort(stacks);
}
