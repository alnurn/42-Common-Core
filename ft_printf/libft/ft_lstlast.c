/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 11:40:17 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/25 14:53:48 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		if (!(ptr->next))
			return (ptr);
		else
			ptr = ptr->next;
	}
	return (ptr);
}

/*int	main(void
{
	t_list	*ptr;

	ptr = NULL;
	ft_lstadd_back(&ptr, ft_lstnew((void *)1));

	if (ft_lstlast(ptr)->content == (void*)1)
		printf("Correct!\n");
}*/
