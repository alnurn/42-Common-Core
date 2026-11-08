/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:50:17 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/16 18:32:05 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

const std::string&	Weapon::getType() const
{
	const std::string&	ref = _type;
	return (ref);
}
