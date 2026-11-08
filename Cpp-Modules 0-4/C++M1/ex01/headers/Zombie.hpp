/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:35:51 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/16 17:56:12 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string str);
		~Zombie();
		void	announce();
		void	setName(std::string n);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
