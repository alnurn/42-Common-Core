/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default constructor called\n";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain: Copy constructor called\n";
	*this = other;
}

Brain&	Brain::operator=(const Brain&	other)
{
	std::cout << "Brain: Copy assignment operator called\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called\n";
}

void	Brain::setIdea(const int index, const std::string& idea)
{
	if (index < 0 || index >= 100)
		return ;
	this->ideas[index] = idea;
}

std::string	Brain::getIdea(const int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (this->ideas[index]);
}
