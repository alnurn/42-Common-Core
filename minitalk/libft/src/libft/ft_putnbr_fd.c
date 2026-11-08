/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:06:49 by anurmach          #+#    #+#             */
/*   Updated: 2025/05/24 22:07:03 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	rem;

	if (fd < 0)
		return ;
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	rem = nb % 10 + '0';
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	write(fd, &rem, 1);
}

/*int	main(void)
{
	ft_putnbr_fd(-42, 1);
}*/
