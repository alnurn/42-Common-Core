/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:18:25 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/26 21:18:26 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap(), 
	ScavTrap(), 
	FragTrap()
{
	std::cout << "DiamondTrap: Default constructor called\n";
	this->_name = "Unknown";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap: Name constructor called\n";
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap&	other) :
	ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	_name(other._name)
{
	std::cout << "DiamondTrap: Copy constructor called\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap&	other)
{
	std::cout << "DiamondTrap: Copy assign operator called\n";
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: Destructor called\n";
}

void	DiamondTrap::attack(const std::string&	target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is " << this->_name
			<< ". Its ClapTrap name is " << ClapTrap::_name << ".\n";
}
