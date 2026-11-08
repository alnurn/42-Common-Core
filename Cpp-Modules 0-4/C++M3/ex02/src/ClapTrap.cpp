/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:06:29 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/26 21:06:31 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Default constructor called\n";
}

ClapTrap::ClapTrap(std::string	name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap: Name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap&	other)
{
	std::cout << "ClapTrap: Copy constructor called\n";
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap&	other)
{
	std::cout << "ClapTrap: Copy assignment operator called\n";
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: Destructor called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " is dead\n";
		return ;
	}
	if (!this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy\n";
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target
	 	<< ", causing " << this->_attackDamage << " points of damage!\n";
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " is dead\n";
		return ;
	}
	std::cout << "ClapTrap " << this->_name <<" takes " << amount << " points of damage!\n";
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " is dead\n";
		return ;
	}
	if (!this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy\n";
		return ;
	}
	if (amount <= UINT_MAX - this->_hitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself, restoring " << amount <<" hit points!\n";
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << "Amount is out of range\n";
}
