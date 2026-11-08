/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:26:26 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 18:26:30 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ifsorted(t_list	**stack)
{
	t_list	*ptr;
	t_list	*head;
	int		flag;

	if (!stack || !(*stack))
		return (0);
	ptr = *stack;
	head = *stack;
	flag = 0;
	while (!(flag && ptr == head))
	{
		flag = 1;
		if ((ptr->content > ptr->next->content) && (ptr->next != head))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	ft_dubcheck(t_list	*stack, int value)
{
	t_list	*ptr;
	int		flag;

	ptr = stack;
	flag = 0;
	while (ptr && !(flag && ptr == stack))
	{
		flag = 1;
		if (ptr->content == value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

t_list	*ft_ifhiddensorted(t_list	**stack_a)
{
	t_list	*min;

	if (!stack_a || !(*stack_a))
		return (NULL);
	min = ft_minode(stack_a);
	if (ft_ifsorted(&min))
		return (min);
	else
		return (NULL);
}

void	ft_finalsort(t_stacks *stacks, t_list	*min)
{
	int	i;

	if (!stacks || !(stacks->stack_a) || !min)
		return ;
	i = min->nodecost;
	if (min->index <= stacks->size_a / 2)
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

void	ft_cleanstrings(char	**numbers)
{
	int	i;

	if (!numbers)
		return ;
	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}
