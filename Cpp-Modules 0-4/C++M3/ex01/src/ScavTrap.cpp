/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:01:25 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/26 21:01:29 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap: Default constructor called\n";
	this->_name = "Unknown";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) 
{
	std::cout << "ScavTrap: Name constructor called\n";
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	std::cout << "ScavTrap: Copy constructor called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap&	other)
{
	std::cout << "ScavTrap: Copy assign operator called\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: Destructor called\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->_hitPoints)
	{
		std::cout << "ScavTrap " << this->_name << " is dead\n";
		return ;
	}
	if (!this->_energyPoints)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy\n";
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target
	 	<< ", causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is in Gate keeper mode now.\n";
}
