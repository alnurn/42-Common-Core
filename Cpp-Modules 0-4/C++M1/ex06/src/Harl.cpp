/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:03:33 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/17 13:03:39 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-special-ketchup burger. " 
		"I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. " 
		"You didn’t put enough bacon in my burger! "
		"If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl; 
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! "
		"I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string str)
{
	size_t	i;
	void	(Harl::*ptr[4])(void);
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	ptr[0] = &Harl::debug;
	ptr[1] = &Harl::info;
	ptr[2] = &Harl::warning;
	ptr[3] = &Harl::error;
	i = 0;
	while (i < 4)
	{
		if (str == levels[i])
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			std::cout << "[ " << levels[0] << " ]" << std::endl;
			(this->*ptr[0])();
			std::cout << std::endl;
		//FALLTHROUGH
		case 1:
			std::cout << "[ " << levels[1] << " ]" << std::endl;
			(this->*ptr[1])();
			std::cout << std::endl;
		//FALLTHROUGH
		case 2:
			std::cout << "[ " << levels[2] << " ]" << std::endl;
			(this->*ptr[2])();
			std::cout << std::endl;
		//FALLTHROUGH
		case 3:
			std::cout << "[ " << levels[3] << " ]" << std::endl;
			(this->*ptr[3])();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

