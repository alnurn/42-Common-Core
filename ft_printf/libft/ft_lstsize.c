/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:41:56 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/25 11:46:02 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list	*lst)
{
	int		i;
	t_list	*ptr;

	if (!lst)
		return (0);
	i = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
