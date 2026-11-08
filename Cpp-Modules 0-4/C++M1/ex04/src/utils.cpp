/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 20:25:57 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/17 14:18:14 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string	readFile(std::ifstream& ref)
{
	char		temp;
	std::string	buffer;

	while (ref.get(temp))
		buffer += temp;
	return (buffer);
}

void	modifyBuffer(std::string& buffer, std::string str, std::string rep)
{
	size_t	i;

	i = 0;
	if (str.empty())
		return ;
	while (1)
	{
		i = buffer.find(str, i);
		if (i == std::string::npos)
			break ;
		buffer.erase(i, str.length());
		buffer.insert(i, rep);
		i += rep.length();
	}
}
