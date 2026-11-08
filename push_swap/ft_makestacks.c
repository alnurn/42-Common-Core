/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makestacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:22:39 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 17:51:33 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cleanall(t_stacks	*stacks)
{
	if (!stacks)
		return ;
	ft_lstclear(&(stacks->stack_a));
	ft_lstclear(&(stacks->stack_b));
	free(stacks);
}

int	ft_checknumber(char	*s)
{
	int	i;

	if (!s)
		return (0);
	if (!(s[0] == '+' || s[0] == '-' || ft_isdigit(s[0])))
		return (0);
	if ((s[0] == '+' || s[0] == '-') && !ft_isdigit(s[1]))
		return (0);
	i = 1;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_lstadd(t_stacks	*stacks, int num)
{
	t_list	*newnode;

	newnode = ft_lstnew(num);
	if (!newnode)
		return (0);
	ft_lstadd_back(&(stacks->stack_a), newnode);
	return (1);
}

int	ft_parsing(t_stacks	*stacks, char	**numbers)
{
	int		i;
	long	num;

	i = 0;
	if (!stacks || !numbers || !*numbers)
		return (0);
	while (numbers[i])
	{
		if (!ft_checknumber(numbers[i]))
			return (0);
		num = ft_atol(numbers[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		if (!ft_dubcheck(stacks->stack_a, (int) num))
			return (0);
		if (!ft_lstadd(stacks, (int) num))
			return (0);
		i++;
	}
	return (1);
}

t_stacks	*ft_makestacks(char	**numbers, bool print)
{
	t_stacks	*stacks;

	if (!numbers || !*numbers)
		return (NULL);
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_b = 0;
	stacks->print_op = print;
	if (!ft_parsing(stacks, numbers))
	{
		ft_cleanall(stacks);
		return (NULL);
	}
	stacks->size_a = ft_lstsize(stacks->stack_a);
	return (stacks);
}
