/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:08:33 by anurmach          #+#    #+#             */
/*   Updated: 2025/11/15 13:26:53 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int number)
{
	t_list	*ptr;

	ptr = (t_list *) malloc (sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = number;
	ptr->index = 0;
	ptr->nodecost = 0;
	ptr->generalcost = 0;
	ptr->next = ptr;
	ptr->previous = ptr;
	ptr->target = NULL;
	return (ptr);
}
