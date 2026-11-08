/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:08:31 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/10 12:08:50 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	command;

	while (1)
	{
		if (!std::cin.eof())
			std::cout << "> ";
		if (!std::getline(std::cin, command))
			return (1);
		if (command == "ADD")
			book.add();
		if (command == "SEARCH")
			book.search();
		if (command == "EXIT")
			return (0);
	}
	return (0);
}
