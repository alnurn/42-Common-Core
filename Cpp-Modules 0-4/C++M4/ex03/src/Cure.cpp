/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	/*std::cout << "Cure: Default constructor called\n";*/
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	/*std::cout << "Cure: Copy constructor called\n";*/
}

Cure&	Cure::operator=(const Cure& other)
{
	if (this != &other)
		AMateria::operator=(other);
	/*std::cout << "Cure: Copy assignment operator called\n";*/
	return (*this);
}

Cure::~Cure()
{
	/*std::cout << "Cure: Destructor called\n";*/
}

AMateria *Cure::clone() const
{
	/*std::cout << "Cure: clone function called\n";*/
	AMateria	*ptr = new Cure(*this);
	return (ptr);
}

void	Cure::use(ICharacter&	target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

