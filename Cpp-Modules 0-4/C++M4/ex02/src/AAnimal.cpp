/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("")
{
	std::cout << "AAnimal: Default constructor called\n";
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal: Name constructor called\n";
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "AAnimal: Copy constructor called\n";
	*this = other;
}

AAnimal&	AAnimal::operator=(const AAnimal&	other)
{
	std::cout << "AAnimal: Copy assignment operator called\n";
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal: Destructor called\n";
}

std::string	AAnimal::getType() const
{
	return (type);
}
