/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	/*std::cout << "Ice: Default constructor called\n";*/
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	/*std::cout << "Ice: Copy constructor called\n";*/
}

Ice&	Ice::operator=(const Ice& other)
{
	if (this != &other)
		AMateria::operator=(other);
	/*std::cout << "Ice: Copy assignment operator called\n";*/
	return (*this);
}

Ice::~Ice()
{
	/*std::cout << "Ice: Destructor called\n";*/
}

AMateria *Ice::clone() const
{
	/*std::cout << "Ice: clone function called\n";*/
	AMateria	*ptr = new Ice(*this);
	return (ptr);
}

void	Ice::use(ICharacter&	target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
