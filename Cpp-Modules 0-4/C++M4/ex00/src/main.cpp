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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "**********************\n";
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
	}
	{
		std::cout << "**********************\n";
		Animal	animal("some animal");
		Animal	other(animal);
		Animal	another("another animal");
		std::cout << animal.getType() << std::endl;
		std::cout << other.getType() << std::endl;
		animal = another;
		std::cout << animal.getType() << std::endl;
	}
	{
		std::cout << "**********************\n";
		Dog	dog;
		Dog	dog1(dog);
		dog1 = dog;
		dog.makeSound();
		dog1.makeSound();
	}
	{
		std::cout << "**********************\n";
		Cat	cat;
		Cat	cat1(cat);
		cat1 = cat;
		cat.makeSound();
		cat1.makeSound();
	}
	return (0);
}
