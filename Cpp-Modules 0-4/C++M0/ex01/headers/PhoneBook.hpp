/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:11:01 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/10 12:11:26 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

#define CONTACTS	8
#define INFO		5

class	PhoneBook
{
	private:
		Contact						users[CONTACTS];
		static const std::string	attributes[];
		int							bookCounter;
		int							attemptCounter;
		int							addUser(int index);
		int							checkIndex(std::string index);
		int							printUsers(void);
		int							leadBytes(std::string str);
		int							contBytes(std::string str);
		void						printUser(int index);
		std::string					formatStr(std::string info);
		bool						checkString(std::string s);
	public:
									PhoneBook(void);
									~PhoneBook(void);
		int							add(void);
		int							search(void);
};

#endif
