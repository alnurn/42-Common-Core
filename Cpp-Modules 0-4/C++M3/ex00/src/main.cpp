/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 20:54:18 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/26 20:58:46 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("Adam");
	ClapTrap	b(a);
	ClapTrap	c;
	ClapTrap	d("Mark");
	ClapTrap	e;
	ClapTrap	f("Dave");

	c = a;
	a.attack("Bob");
	for (int i = 0; i < 10; i++)
	{
		a.takeDamage(5);
		a.beRepaired(5);
	}
	a.attack("Bob");
	a.beRepaired(5);
	a.takeDamage(100);
	a.attack("Bob");
	a.beRepaired(5);

	c.takeDamage(15);
	b.takeDamage(10);
	b.beRepaired(10);

	for (int i = 0; i < 10; i++)
		d.attack("Bob");
	d.attack("Bob");
	d.takeDamage(3);
	e = d;
	e.attack("Bob");
	e.beRepaired(5);
	f.beRepaired(UINT_MAX);
	return (0);
}
