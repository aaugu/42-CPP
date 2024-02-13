/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:33:56 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/13 11:32:02 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "../includes/BitcoinExchange.hpp"

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(void) {
	try {
		createDatabase("data/data.csv");
	}
	catch(const std::exception& e) {
		std::cerr << "Error: "<< e.what() << std::endl;
	}
}

// TO DO
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	this->_database = src._database;
}

BitcoinExchange::~BitcoinExchange(void) {}

// TO DO
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src) {
	this->_database = src._database;
	return ( *this );
}

/* ************************************************************************** */
/*                          PUBLIC MEMBER FUNCTIONS                           */
/* ************************************************************************** */

// ---------------------- Main public member function ----------------------- //
void BitcoinExchange::bitcoinValues(std::string inputFile)
{
	double		value = 0;
	time_t		date = 0;
	time_t		closestDate = 0;

	std::ifstream	iFS;
	try {
		openFile(&iFS, inputFile);
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::string		line;
	while (std::getline(iFS, line))
	{
		if (line == "date | value" || line.empty())
			continue ;
		try {
			checkInputFormat(line);
			date = getDateInEpochTime(line.substr(0, line.find('|') - 1));
			value = getValue(line.substr(line.find('|') + 2, line.size() - 1), INPUT);
			closestDate = findClosestDate(date);
			printBitcoinValue(closestDate, line.substr(0, 10), value);
		}
		catch(const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			continue ;
		}
	}
}

/* ************************************************************************** */
/*                          PRIVATE MEMBER FUNCTIONS                          */
/* ************************************************************************** */

// ----------------------- Constructor util function ------------------------ //
void BitcoinExchange::createDatabase(std::string dataFile)
{
	double		value = 0;
	time_t		date = 0;

	std::ifstream	iFS;
	try {
		openFile(&iFS, dataFile);
	}
	catch(const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::string		line;
	while (std::getline(iFS, line))
	{
		if (line == "date,exchange_rate" || line.empty())
			continue ;
		try {
			if (line.find(',') > line.size())
				throw std::runtime_error( "bad input => " + line );
			date = getDateInEpochTime( line.substr(0, line.find(',')) );
			value = getValue( line.substr(line.find(',') + 1, line.size() - 1), DATABASE );
			_database.insert( std::pair<time_t, double>( date, value ) );
		}
		catch(const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			continue ;
		}
	}
}

// ---------------------- Main function sub functions ----------------------- //
void	BitcoinExchange::openFile(std::ifstream* iFS, std::string inputFile)
{
	iFS->open(inputFile.c_str(), std::fstream::in);
	if (!iFS->good())
		throw std::runtime_error("could not open file.");
}

void	BitcoinExchange::checkInputFormat(std::string line)
{
	if (	line.find('|') > line.size() &&
			line[line.find('|') - 1] != ' ' &&
			line[line.find('|') + 1] != ' ' 	)
		throw std::runtime_error("bad input => " + line);
}

time_t	BitcoinExchange::getDateInEpochTime(std::string date)
{
	int	year = 0;
	int	month = 0;
	int	day = 0;

	checkInputDate(date);
	extractDateInfos(date, &year, &month, &day);
	checkDateValidity(year, month, day);

	return (convertToEpochDate(year, month, day) );
}

double	BitcoinExchange::getValue(std::string sValue, int type)
{
	checkInputValue(sValue);
	double	value = convertToValue(sValue);
	checkValueValidity(value, type);

	return (value);
}

time_t	BitcoinExchange::findClosestDate(time_t date)
{
	time_t	minDateLimit = _database.begin()->first;
	time_t	maxDateLimit = _database.rbegin()->first;
	// std::cout << minDateLimit << " " << maxDateLimit << " " << date << std::endl;

	if (date < minDateLimit)
		throw std::out_of_range("No data before this date.");
	if (date > maxDateLimit)
		return (maxDateLimit);

	time_t	diff = -1;
	time_t	closestDiff = date - _database.begin()->first;
	time_t	closestDate = _database.begin()->first;

	for (std::map<time_t, double>::iterator it = _database.begin(); it != _database.end(); ++it)
    {
		diff = date - it->first;
		if (diff >= 0 && diff < closestDiff)
		{
			closestDiff = diff;
			closestDate = it->first;
		}
	}
	return (closestDate);
}

void BitcoinExchange::printBitcoinValue(time_t closestDate, std::string date, double value)
{
	std::cout	<< date << " => " << value << " = " << value * _database.at(closestDate)
				<< std::endl;
}

// ----------------------------- Date Handling ------------------------------ //

void	BitcoinExchange::checkInputDate(std::string date)
{
	if (date.size() != 10)
		throw std::runtime_error("bad input => " + date);
	size_t	yearSize = date.find('-', 0);
	size_t	monthSize = date.find('-', yearSize + 1) - yearSize - 1;
	size_t	daySize = date.size() - date.find('-', yearSize + 1) - 1;

	if (yearSize != 4 || monthSize != 2 || daySize != 2)
		throw std::runtime_error("bad input => " + date);

	date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
	for (int i = 0; i < 8; i++)
	{
		if (std::isdigit(date[i]) == false)
			throw std::runtime_error("bad input => " + date);
	}
}

void	BitcoinExchange::extractDateInfos(std::string date, int* year, int *month, int* day)
{
	char* 		endptr;

	*year = static_cast<int>(strtol(date.substr(0, 4).c_str(), &endptr, 10));
	*month = static_cast<int>(strtol(date.substr(5, 6).c_str(), &endptr, 10));
	*day = static_cast<int>(strtol(date.substr(8, 9).c_str(), &endptr, 10));
}

void	BitcoinExchange::checkDateValidity(int year, int month, int day)
{
	if (	invalidMonth(month) ||
			invalidDay(month, day) ||
			(isLeapYear(year) == false && month == 2 && day > 28) )
		{
			throw std::out_of_range("invalid date");
		}
}

bool	BitcoinExchange::invalidMonth(int month) {
	return ( (month < 1) || (month > 12) );
}

bool	BitcoinExchange::invalidDay(int month, int day)
{
	int	maxNbDaysOfMonth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (day < 1 || day > maxNbDaysOfMonth[month - 1])
		return ( true );
	return ( false );
}

bool BitcoinExchange::isLeapYear(int year) {
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0)
        return false;
    else if (year % 4 == 0)
        return true;
    else
        return false;
}

std::time_t	BitcoinExchange::convertToEpochDate(int year, int month, int day)
{
	std::tm tm;

	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	tm.tm_hour = 10;
	tm.tm_min = 42;
	tm.tm_sec = 0;

	return (std::mktime(&tm));
}

// ----------------------------- Value Handling ----------------------------- //

void	BitcoinExchange::checkInputValue(std::string value)
{
	bool	dot = false;
	size_t	i = 0;

	if (value[0] == '-')
		i++;

	while (i < value.size())
	{
		if (value[i] == '.' && dot == false)
		{
			dot = true;
			i++;
		}
		else if (value[i] == '.' && dot == true)
			throw std::runtime_error("bad input => invalid value");
		if (std::isdigit(value[i]) == false)
			throw std::runtime_error("bad input => invalid value");
		i++;
	}
}

double	BitcoinExchange::convertToValue(std::string value)
{
	char* 	endptr;
	return (strtod(value.c_str(), &endptr));
}

void	BitcoinExchange::checkValueValidity(double value, int type) {
	if (value < 0)
		throw std::out_of_range("not a positive number.");

	if (type == INPUT)
	{
		if (value > 1000)
			throw std::out_of_range("too large a number.");
	}
}
