/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:09:07 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/10 12:09:35 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

const std::string PhoneBook::attributes[] = 
{ 
	" first name: ",
	" last name: ",
	" nickname: ",
	" phone number: ",
	" darkest secret: "
};

PhoneBook::PhoneBook(void): bookCounter(0), attemptCounter(0)
{
	std::cout << std::endl;
	std::cout << "*****************PHONE BOOK*****************" << std::endl;
	std::cout << "'ADD' - save a new contact (8 max)." << std::endl;
	std::cout << "'SEARCH' - display a specific contact." << std::endl;
	std::cout << "'EXIT' - the program quits." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PHONE BOOK CANCELLED" << std::endl;
}

/*------------------------------------ADD------------------------------------*/

bool	PhoneBook::checkString(std::string s)
{
	size_t	i;

	if (s.empty())
		return (false);
	i = 0;
	while (i < s.length())
	{
		if (!std::isspace(s[i]))
			return (true);
		i++;
	}
	return (false);
}

int	PhoneBook::addUser(int	index)
{
	int		i;
	std::string	buff;

	i = 0;
	while (i < INFO)
	{
		std::cout << "> Enter a" << attributes[i];
		if (!std::getline(std::cin, buff))
		{
			std::cout << std::endl;
			break ;
		}
		if (!checkString(buff))
			continue ;
		if (i == 0)
		{
			users[index].setFirstName(buff);
			i++;
		}
		else if (i == 1)
		{
			users[index].setLastName(buff);
			i++;
		}
		else if (i == 2)
		{
			users[index].setNickName(buff);
			i++;
		}
		else if (i == 3)
		{
			users[index].setPhoneNumber(buff);
			i++;
		}
		else if (i == 4)
		{
			users[index].setSecret(buff);
			i++;
		}
	}
	if (i != INFO)
		return (0);
	return (1);
}

int	PhoneBook::add(void)
{
	int	index;

	index = attemptCounter % CONTACTS;
	std::cout << "*************ADDING CONTACT N." << index + 1;
	std::cout << "*************" << std::endl;
	if (addUser(index))
	{
		if (bookCounter < CONTACTS)
			bookCounter++;
		attemptCounter++;
		return (1);
	}
	else
		return (0);
}

/*------------------------------------SEARCH------------------------------------*/

int	PhoneBook::leadBytes(std::string str)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 0;
	while (str[i])
	{
		if (!((str[i] & 0xC0) == 0x80))
			bytes++;
		i++;
	}
	return (bytes);
}

int	PhoneBook::contBytes(std::string str)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 0;

	while (str[i])
	{
		if (((str[i] & 0xC0) == 0x80))
			bytes++;
		i++;
	}
	return (bytes);
}

std::string	PhoneBook::formatStr(std::string info)
{
	std::string	str;
	int			bytes;
	int			i;

	str = info;
	i = 0;
	bytes = 0;
	if (leadBytes(str) > 10)
	{
		while (str[i])
		{
			if (bytes == 9 && !((str[i] & 0xC0) == 0x80))
				return (str.substr(0, i) + ".");
			if (!((str[i] & 0xC0) == 0x80))
				bytes++;
			i++;
		}
	}
	return (info);
}

int	PhoneBook::printUsers(void)
{
	int			i;
	int			conts;
	std::string	str;

	i = 0;
	if (!bookCounter)
	{
		std::cout << "PLEASE ADD AT LEAST ONE USER." << std::endl;
		return (0);
	}
	std::cout << "*******************SEARCH******************" << std::endl;
	while (i < bookCounter)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		str = formatStr(users[i].getFirstName());
		conts = contBytes(str);
		std::cout << std::setw(10 + conts) << str << "|";
		str = formatStr(users[i].getLastName());
		conts = contBytes(str);
		std::cout << std::setw(10 + conts) << str << "|";
		str = formatStr(users[i].getNickName());
		conts = contBytes(str);
		std::cout << std::setw(10 + conts) << str <<  std::endl;
		i++;
	}
	return (1);
}

void	PhoneBook::printUser(int index)
{
	std::cout << attributes[0] << users[index].getFirstName() << std::endl;
	std::cout << attributes[1] << users[index].getLastName() << std::endl;
	std::cout << attributes[2] << users[index].getNickName() << std::endl;
	std::cout << attributes[3] << users[index].getPhoneNumber() << std::endl;
	std::cout << attributes[4] << users[index].getSecret() << std::endl;
}

int	PhoneBook::checkIndex(std::string	index)
{
	if (index.length() != 1)
		return (-1);
	if (index[0] >= '1' && index[0] <= '8')
		return (index[0] - '0' - 1);
	return (-1);
}

int	PhoneBook::search(void)
{
	std::string	index;
	int		value;

	if (!printUsers())
		return (0);
	while (1)
	{
		std::cout << "> Enter a user index: ";
		if (!std::getline(std::cin, index))
		{
			std::cout << std::endl;
			return (0);
		}
		value = checkIndex(index);
		if (value == -1 || value >= bookCounter)
			std::cout << "PLEASE ENTER VALID USER INDEX" << std::endl;
		else
			return (printUser(value), 1);
	}
	return (0);
}
