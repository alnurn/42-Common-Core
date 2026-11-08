/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("")
{
	std::cout << "WrongAnimal: Default constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal: Name constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal: Copy constructor called\n";
	*this = other;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal&	other)
{
	std::cout << "WrongAnimal: Copy assignment operator called\n";
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
	
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called\n";
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal makes sound\n";	
}

std::string	WrongAnimal::getType() const
{
	return (type);
}
