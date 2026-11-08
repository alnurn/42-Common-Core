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
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other) :
	Animal(other)
{
	this->_brain = new Brain();
	*this->_brain = *other._brain;
	std::cout << "Cat: Copy constructor called\n";
}

Cat&	Cat::operator=(const Cat&	other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*this->_brain = *other._brain;
	}
	std::cout << "Cat: Copy assignment operator called\n";
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat: Destructor called\n";
}

void	Cat::makeSound() const
{
	std::cout << this->type << ": Meow meow!\n";
}

void	Cat::setIdea(const int index, const std::string& idea)
{
	this->_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(const int index) const
{
	return (this->_brain->getIdea(index));
}
