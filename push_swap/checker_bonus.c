/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 15:22:39 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 17:51:33 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_oper(t_stacks	*stacks, const char	*line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		ft_sa(stacks);
	else if (!ft_strncmp(line, "sb\n", 3))
		ft_sb(stacks);
	else if (!ft_strncmp(line, "ss\n", 3))
		ft_ss(stacks);
	else if (!ft_strncmp(line, "pa\n", 3))
		ft_pa(stacks);
	else if (!ft_strncmp(line, "pb\n", 3))
		ft_pb(stacks);
	else if (!ft_strncmp(line, "ra\n", 3))
		ft_ra(stacks);
	else if (!ft_strncmp(line, "rb\n", 3))
		ft_rb(stacks);
	else if (!ft_strncmp(line, "rr\n", 3))
		ft_rr(stacks);
	else if (!ft_strncmp(line, "rra\n", 4))
		ft_rra(stacks);
	else if (!ft_strncmp(line, "rrb\n", 4))
		ft_rrb(stacks);
	else if (!ft_strncmp(line, "rrr\n", 4))
		ft_rrr(stacks);
	else
		return (0);
	return (1);
}

void	ft_readcommands(t_stacks	*stacks)
{
	char	*line;
	int		flag;

	flag = 1;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!ft_oper(stacks, (const char *) line))
			flag = 0;
		free(line);
	}
	if (!flag)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return ;
	}
	if (ft_ifsorted(&(stacks->stack_a)) && !stacks->stack_b)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

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
		stacks = ft_makestacks(numbers, false);
		ft_cleanstrings(numbers);
	}
	else if (argc > 2)
		stacks = ft_makestacks(argv + 1, false);
	if (!stacks)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (0);
	}
	ft_readcommands(stacks);
	ft_cleanall(stacks);
}
