/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:22:39 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 17:51:33 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_stacks	*stacks;
	char		**numbers;

	stacks = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		numbers = ft_split((const char *) argv[1], ' ');
		stacks = ft_makestacks(numbers, true);
		ft_cleanstrings(numbers);
	}
	else if (argc > 2)
		stacks = ft_makestacks(argv + 1, true);
	if (!stacks)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (0);
	}
	ft_generalsort(stacks);
	ft_cleanall(stacks);
	return (0);
}
