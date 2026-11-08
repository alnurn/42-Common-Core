/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:07:55 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/10 12:08:21 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setFirstName(std::string s)
{
	_firstName = s;
}

void	Contact::setLastName(std::string s)
{
	_lastName = s;
}

void	Contact::setNickName(std::string s)
{
	_nickName = s;
}

void	Contact::setPhoneNumber(std::string s)
{
	_phoneNumber = s;
}

void	Contact::setSecret(std::string s)
{
	_secret = s;
}

std::string	Contact::getFirstName(void) const
{
	return (_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (_lastName);
}

std::string	Contact::getNickName(void) const
{
	return (_nickName);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (_phoneNumber);
}

std::string	Contact::getSecret(void) const
{
	return (_secret);
}
