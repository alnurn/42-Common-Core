/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>
#include <string>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	/*std::cout << "MateriaSource: Default constructor called\n";*/
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	/*std::cout << "MateriaSource: Name constructor called\n";*/
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (other._materias[i])
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
	/*std::cout << "Character: Destructor called\n";*/
}

void	MateriaSource::learnMateria(AMateria	*ptr)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materias[i])
		{
			if (ptr)
			{
				this->_materias[i] = ptr->clone();
				delete ptr;
				return ;
			}
		}
	}
	if (ptr)
		delete ptr;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i ++)
	{
		if (this->_materias[i])
		{
			if (this->_materias[i]->getType() == type)
				return (this->_materias[i]->clone());
		}
	}
	return (NULL);
}
