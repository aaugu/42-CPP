/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:51:22 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/17 09:44:52 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int		openInFileStream(std::ifstream* iFS, std::string inFile);
int		openOutFileStream(std::ofstream* oFS, std::string outFile);
void	fillOutFile(std::ifstream* iFS,	std::ofstream* oFS, std::string target, std::string replace);

/*
	Create a program that takes three parameters in the following order: a filename and
	two strings, s1 (target) and s2 (replace).
	It will open the file <filename> and copies its content into a new file
	<filename>.replace, replacing every occurrence of s1 with s2.
*/
int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Error: Wrong number of arguments" << std::endl, 1);
	
	std::ifstream	iFS;
	std::string 	inFile = av[1];
	if (openInFileStream(&iFS, inFile) == -1)
		return (1);
	
	std::ofstream	oFS;
	std::string		outFile = inFile.append(".replace");
	if (openOutFileStream(&oFS, outFile) == -1)
		return (1);

	fillOutFile(&iFS, &oFS, av[2], av[3]);

	oFS.close();
	iFS.close();
	
	return (0);
}

int	openInFileStream(std::ifstream* iFS, std::string inFile)
{
	(*iFS).open(inFile, std::fstream::in);
	if (!(*iFS).is_open())
		return (std::cout << "Error: Could not open file" << std::endl, -1);
	return (0);
}

int	openOutFileStream(std::ofstream* oFS, std::string outFile)
{
	(*oFS).open(outFile, std::fstream::out);
	if (!(*oFS).is_open())
		return (std::cout << "Error: Could not create file" << std::endl, -1);
	return (0);
}

void	fillOutFile(std::ifstream* iFS,	std::ofstream* oFS, std::string target, std::string replace)
{
	std::string		line;

	while (std::getline(*iFS, line))
	{
		if (line.compare(target) == 0)
			*oFS << replace << std::endl;
		else
			*oFS << line << std::endl;
	}
}