/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:55:24 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/13 16:49:23 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int	main(void)
{
	{
		std::cout << "***************************\n";
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "***************************\n";
		AMateria	*materias[] =
		{
			new Ice(),
			new Cure(),
			new Ice(),
			new Cure()
		};
		Character	*characters[] = 
		{
			new Character("Alnur"),
			new Character("Bob")
		};
		for (int i = 0; i < 4; i++)
			characters[0]->equip(materias[i]);
		for (int i = 0; i < 4; i++)
			characters[0]->use(i, *characters[1]);
		*characters[1] = *characters[0];
		for (int i = 0; i < 4; i++)
			characters[1]->use(i, *characters[0]);
		delete characters[0];
		delete characters[1];
	}
	{
		std::cout << "***************************\n";
		Character	alnur("Alnur");
		Character	bob;

		bob = alnur;
		std::cout << alnur.getName() << std::endl;
		std::cout << bob.getName() << std::endl;
	}
	{
		std::cout << "***************************\n";
		ICharacter	*ptr = new Character("Alnur");

		std::cout << ptr->getName() << std::endl;
		delete ptr;
	}
	{
		std::cout << "***************************\n";
		Ice	ice;
		Ice	ice1(ice);

		std::cout << ice.getType() << std::endl;
		std::cout << ice1.getType() << std::endl;
	}
	{
		std::cout << "***************************\n";
		Ice	ice;
		Cure	cure;

		std::cout << ice.getType() << std::endl;
		std::cout << cure.getType() << std::endl;
		AMateria	*a = &ice;
		AMateria	*b = &cure;
		*a = *b;
		std::cout << a->getType() << std::endl;
		std::cout << b->getType() << std::endl;
	}
	{
		std::cout << "***************************\n";
		Ice	ice;
		Cure	cure;

		std::cout << ice.getType() << std::endl;
		std::cout << cure.getType() << std::endl;
		AMateria& a = ice;
		AMateria& b = cure;
		a = b;
		std::cout << a.getType() << std::endl;
		std::cout << b.getType() << std::endl;
	}
	{
		std::cout << "***************************\n";
		AMateria	*ptr = new Ice();
		AMateria	*ptr1 = new Cure();

		std::cout << ptr->getType() << std::endl;
		std::cout << ptr1->getType() << std::endl;

		AMateria	*ptr_copy = ptr->clone();
		std::cout << ptr_copy->getType() << std::endl;
	
		AMateria	*ptr1_copy = ptr1->clone();
		std::cout << ptr1_copy->getType() << std::endl;
		delete ptr;
		delete ptr1;
		delete ptr_copy;
		delete ptr1_copy;
	}
	return (0);
}
