/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:06:51 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/26 21:06:53 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a("Adam");
	FragTrap	b;

	a.takeDamage(50);
	b = a;
	a.highFivesGuys();
	b.takeDamage(50);
	b.attack("Bob");
	b.highFivesGuys();

	for (int i = 0; i < 100; i++)
		a.attack("Bob");
	a.attack("Bob");
	FragTrap	c(a);
	c.attack("Bob");
	return (0);
}
