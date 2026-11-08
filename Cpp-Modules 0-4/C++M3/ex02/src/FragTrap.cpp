/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:06:40 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/26 21:06:42 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap: Default constructor called\n";
	this->_name = "Unknown";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap: Name constructor called\n";
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap&	other): ClapTrap(other)
{
	std::cout << "FragTrap: Copy constructor called\n";
}

FragTrap&	FragTrap::operator=(const FragTrap&	other)
{
	std::cout << "FragTrap: Copy assign operator called\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: Destructor called\n";
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " : Give me five!\n";
}
