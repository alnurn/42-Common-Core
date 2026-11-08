/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:05:01 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/10 12:06:25 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>


void	print_up(std::string	s)
{	
	size_t	j;

	j = 0;
	while (j < s.length())
	{
		std::cout << static_cast<char>(std::toupper(s[j]));
		j++;
	}
}

int	main(int argc, char	**argv)
{
	int	i;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		print_up(argv[i]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}
