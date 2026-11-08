/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:30:13 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 18:30:16 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stacks
{
	int		size_a;
	int		size_b;
	t_list	*stack_a;
	t_list	*stack_b;
	bool	print_op;
}	t_stacks;

/*ft_helpers.c*/
int			ft_ifsorted(t_list	**stack);
int			ft_dubcheck(t_list	*stack, int value);
t_list		*ft_ifhiddensorted(t_list	**stack_a);
void		ft_finalsort(t_stacks	*stacks, t_list	*min);
void		ft_cleanstrings(char	**numbers);

/*ft_movetotop.c*/
void		ft_movetotop(t_stacks	*stacks);

/*ft_movetotopback.c*/
void		ft_movetotopback(t_stacks	*stacks);

/*ft_indexcost.c*/
void		ft_indexation(t_stacks	*stacks);
void		ft_topcost(t_list	**stack, int size);
void		ft_costcalculate(t_list	**src, int srcsize, int dstsize);
t_list		*ft_findmincost(t_list	**stack);

/*ft_findtarget.c*/
void		ft_findnode(t_list	*src, t_list	*dst);
void		ft_findtarget(t_list	*src, t_list	*dst);

/*ft_findtargetback.c*/
void		ft_findnodeback(t_list	**src, t_list	**dst);
void		ft_findtargetback(t_list	**src, t_list	**dst);

/*ft_minmax.c*/
t_list		*ft_maxnode(t_list	**stack);
t_list		*ft_minode(t_list	**stack);

/*ft_generalsort.c*/
void		ft_generalsort(t_stacks	*stacks);
void		ft_pushtoa(t_stacks	*stacks);

/*ft_twothreesort.c*/
void		ft_twothreesort(t_stacks	*stacks);

/*ft_makestacks.c*/
t_stacks	*ft_makestacks(char	**numbers, bool print);
void		ft_cleanall(t_stacks	*stacks);

/*ft_swap.c*/
void		ft_sa(t_stacks	*stacks);
void		ft_sb(t_stacks	*stacks);
void		ft_ss(t_stacks	*stacks);

/*ft_rotate.c*/
void		ft_ra(t_stacks	*stacks);
void		ft_rb(t_stacks	*stacks);
void		ft_rr(t_stacks	*stacks);

/*ft_revrotate.c*/
void		ft_rra(t_stacks	*stacks);
void		ft_rrb(t_stacks	*stacks);
void		ft_rrr(t_stacks	*stacks);

/*ft_push.c*/
void		ft_pa(t_stacks *stacks);
void		ft_pb(t_stacks *stacks);

#endif