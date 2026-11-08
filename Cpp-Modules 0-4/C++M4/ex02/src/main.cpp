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

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		std::cout << "******************\n";
		AAnimal	*ptrs[10];

		for (int i = 0; i < 5; i++)
			ptrs[i] = new Dog();
		for (int i = 5; i < 10; i++)
			ptrs[i] = new Cat();
		for (int i = 0; i < 10; i ++)
			delete ptrs[i];
	}
	/*{
		AAnimal	animal;
	}*/
	{
		std::cout << "******************\n";
		Cat	cat1;
		cat1.setIdea(0, "I love fish");
		Cat	cat2(cat1);
		cat2.setIdea(0, "I love meat");
		std::cout << "cat1: " << cat1.getIdea(0) << std::endl;
		std::cout << "cat2: " << cat2.getIdea(0) << std::endl;
	}
	{
		std::cout << "******************\n";
		Dog	dog1;
		dog1.setIdea(0, "I love bone");
		Dog	dog2(dog1);
		dog2.setIdea(0, "I love meat");
		std::cout << "dog1: " << dog1.getIdea(0) << std::endl;
		std::cout << "dog2: " << dog2.getIdea(0) << std::endl;
	}
	{
		std::cout << "******************\n";
		Dog	dog1;
		dog1.setIdea(0, "I love bone");
		Dog	dog2;
		dog2 = dog1;
		dog2.setIdea(0, "I love meat");
		std::cout << "dog1: " << dog1.getIdea(0) << std::endl;
		std::cout << "dog2: " << dog2.getIdea(0) << std::endl;
	}
	{
		std::cout << "******************\n";
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout << "******************\n";
		AAnimal	*ptr = new Cat();
		Cat	cat1;
		Cat	cat2(cat1);

		delete ptr;
	}
	{
		std::cout << "******************\n";
		Cat	*ptr1 = new Cat();
		Cat	*ptr2 = new Cat();

		*ptr1 = *ptr2;
		delete ptr1;
		delete ptr2;
	}
	{
		std::cout << "******************\n";
		Dog	*ptr1 = new Dog();
		Dog	*ptr2 = new Dog();

		*ptr1 = *ptr2;
		delete ptr1;
		delete ptr2;
	}
	return (0);
}
