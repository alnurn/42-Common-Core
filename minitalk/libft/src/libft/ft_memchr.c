/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:01:37 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 17:04:24 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	i = 0;
	if (!s)
		return (NULL);
	ptr = (const unsigned char *) s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return ((void *) &ptr[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", (char *) ft_memchr("hello, world", ' ', 13));
	ft_memchr(NULL, ' ', 10);
}*/
