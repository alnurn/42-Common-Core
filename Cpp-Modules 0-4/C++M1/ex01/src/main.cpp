/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:53:40 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/16 17:10:08 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N;
	Zombie	*z;

	N = 10;
	z = zombieHorde(N, "Foo");
	if (!z)
		return (1);
	for (int i = 0; i < N; i++)
		z[i].announce();
	delete[] z;
	return (0);
}
