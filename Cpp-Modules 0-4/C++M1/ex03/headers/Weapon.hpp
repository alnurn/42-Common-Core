/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 17:49:48 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/16 18:33:04 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class	Weapon
{
	private:
		std::string			_type;
	public:
		Weapon(std::string type);
		void				setType(std::string type);
		const std::string&	getType() const;
};

#endif
