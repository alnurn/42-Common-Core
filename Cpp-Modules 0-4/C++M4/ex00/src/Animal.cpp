/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Animal: Default constructor called\n";
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal: Name constructor called\n";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal: Copy constructor called\n";
	*this = other;
}

Animal&	Animal::operator=(const Animal&	other)
{
	std::cout << "Animal: Copy assignment operator called\n";
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called\n";
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes sound\n";
}

std::string	Animal::getType() const
{
	return (type);
}
