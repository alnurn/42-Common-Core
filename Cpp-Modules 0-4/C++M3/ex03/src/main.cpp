/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:17:55 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/26 21:18:47 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	adam("Adam");
	DiamondTrap	eva;

	eva = adam;
	DiamondTrap	person(eva);
	adam.whoAmI();
	eva.whoAmI();
	person.whoAmI();
	adam.guardGate();
	adam.highFivesGuys();
	adam.attack("Bob");
	adam.takeDamage(50);
	for (int i = 0; i < 50; i++)
		adam.beRepaired(50);
	return (0);
}
