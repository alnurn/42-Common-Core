/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:00:34 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/26 21:01:01 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("Adam");
	ScavTrap	b;

	a.takeDamage(50);
	b = a;
	a.guardGate();
	b.takeDamage(50);
	b.attack("Bob");
	b.guardGate();
	for (int i = 0; i < 50; i++)
		a.attack("Bob");
	a.attack("Bob");
	ScavTrap	c(a);
	c.attack("Bob");
	return (0);
}
