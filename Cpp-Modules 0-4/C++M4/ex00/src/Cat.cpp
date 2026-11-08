/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() :
	Animal("Cat")
{
	std::cout << "Cat: Default constructor called\n";
}

Cat::Cat(const Cat& other) :
	Animal(other)
{
	std::cout << "Cat: Copy constructor called\n";
}

Cat&	Cat::operator=(const Cat&	other)
{
	std::cout << "Cat: Copy assignment operator called\n";
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << this->type << ": Meow meow!\n";
}
