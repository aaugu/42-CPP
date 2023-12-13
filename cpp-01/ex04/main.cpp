/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:51:22 by aaugu             #+#    #+#             */
/*   Updated: 2023/12/07 16:43:28 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <errno.h>

int		openInFileStream(std::ifstream* iFS, std::string inFile);
int		openOutFileStream(std::ofstream* oFS, std::string outFile);
void	fillOutFile(std::ifstream* iFS,	std::ofstream* oFS, std::string target, std::string replace);
void	replaceTarget(std::string *line, std::string target, std::string replace, size_t pos);

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
	iFS->open(inFile, std::fstream::in);
	if (!iFS->good())
	{
		std::cout << "Error:" << inFile << ": " << strerror(errno) << std::endl;
		return (-1);
	}
	return (0);
}

int	openOutFileStream(std::ofstream* oFS, std::string outFile)
{
	oFS->open(outFile, std::fstream::out);
	if (!oFS->good())
	{
		std::cout << "Error:" << outFile << ": " << strerror(errno) << std::endl;
		return (-1);
	}
	return (0);
}

void	fillOutFile(std::ifstream* iFS,	std::ofstream* oFS, std::string target, std::string replace)
{
	std::string	line;
	size_t		pos = 0;

	while (std::getline(*iFS, line))
	{
		if (target.empty())
			*oFS << line << std::endl;
		else
		{
			pos = line.find(target.c_str(), 0, target.size());
			if (pos == std::string::npos)
				*oFS << line << std::endl;
			else
			{
				replaceTarget(&line, target, replace, pos);
				*oFS << line << std::endl;
			}
		}
	}
}

void	replaceTarget(std::string *line, std::string target, std::string replace, size_t pos)
{
	while (pos != std::string::npos)
	{
		line->erase(pos, target.size());
		if (!replace.empty())
			line->insert(pos, replace);
		pos = line->find(target.c_str(), 0, target.size());
	}
}