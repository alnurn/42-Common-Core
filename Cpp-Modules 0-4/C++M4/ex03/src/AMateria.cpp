/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria() : _type("Unknown")
{
	/*std::cout << "AMateria: Default constructor called\n";*/
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	/*std::cout << "AMateria: Name constructor called\n";*/
}

AMateria::AMateria(const AMateria& other)
{
	/*std::cout << "AMateria: Copy constructor called\n";*/
	this->_type = other._type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	(void) other;
	/*std::cout << "AMateria: Copy assignment operator called\n";*/
	return (*this);
}

AMateria::~AMateria()
{
	/*std::cout << "AMaterial: Destructor called\n";*/
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter&	target)
{
	(void) target;
}


