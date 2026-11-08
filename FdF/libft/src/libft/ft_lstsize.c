/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:41:56 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/17 17:18:32 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list	*lst)
{
	int		i;
	t_list	*ptr;
	t_list	*head;

	if (!lst)
		return (0);
	i = 0;
	ptr = lst;
	head = lst;
	while (1)
	{
		i++;
		if (ptr->next == head)
			return (i);
		ptr = ptr->next;
	}
	return (i);
}
