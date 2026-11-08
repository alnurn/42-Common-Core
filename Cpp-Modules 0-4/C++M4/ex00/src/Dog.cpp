/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() :
	Animal("Dog")
{
	std::cout << "Dog: Default constructor called\n";
}

Dog::Dog(const Dog& other) :
	Animal(other)
{
	std::cout << "Dog: Copy constructor called\n";
}

Dog&	Dog::operator=(const Dog&	other)
{
	std::cout << "Dog: Copy assignment operator called\n";
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << this->type << ": Woof-woof!\n";
}
