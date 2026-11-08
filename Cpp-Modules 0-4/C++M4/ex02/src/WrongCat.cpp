/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() :
	WrongAnimal("WrongCat")
{
	std::cout << "WrongCat: Default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) :
	WrongAnimal(other)
{
	std::cout << "WrongCat: Copy constructor called\n";
}

WrongCat&	WrongCat::operator=(const WrongCat&	other)
{
	std::cout << "WrongCat: Copy assignment operator called\n";
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called\n";
}

void	WrongCat::makeSound() const
{
	std::cout << this->type << ": Meow meow!\n";
}
