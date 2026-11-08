/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 19:15:07 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/16 20:24:02 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int	main(int argc, char	**argv)
{
	std::ifstream	src;
	std::ofstream	dst;
	std::string		buffer;
	std::string		newfile;

	if (argc != 4)
	{
		std::cout << "Error: wrong number of arguments." << std::endl;
		return (1);
	}
	src.open(argv[1]);
	if (src.fail())
	{
		std::cout << "Error: wrong name of the file." << std::endl;
		return (2);
	}
	buffer = readFile(src);
	if (!src.eof())
	{
		std::cout << "Error: reading failed." << std::endl;
		return (2);
	}
	src.close();
	modifyBuffer(buffer, argv[2], argv[3]);
	newfile = argv[1];
	newfile += ".replace";
	dst.open(newfile.c_str());
	if (dst.fail())
	{
		std::cout << "Error: creating new file failed." << std::endl;
		return (4);
	}
	dst << buffer;
	dst.close();
	if (!dst)
	{
		std::cout << "Error: writing file failed." << std::endl;
		return (5);
	}
	return (0);
}
