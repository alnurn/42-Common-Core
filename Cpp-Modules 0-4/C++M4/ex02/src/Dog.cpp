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
	AAnimal("Dog")
{
	std::cout << "Dog: Default constructor called\n";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) :
	AAnimal(other)
{
	this->_brain = new Brain();
	*this->_brain = *other._brain;
	std::cout << "Dog: Copy constructor called\n";
}

Dog&	Dog::operator=(const Dog&	other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		*this->_brain = *other._brain;
	}
	std::cout << "Dog: Copy assignment operator called\n";
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog: Destructor called\n";
}

void	Dog::makeSound() const
{
	std::cout << this->type << ": Woof-woof!\n";
}

void	Dog::setIdea(const int index, const std::string& idea)
{
	this->_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(const int index) const
{
	return (this->_brain->getIdea(index));
}
