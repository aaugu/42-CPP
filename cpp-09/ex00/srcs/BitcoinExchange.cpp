/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:33:56 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/12 13:31:11 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include "../includes/BitcoinExchange.hpp"

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::string dataFile) {
	createDatabase(dataFile);
	minDateLimit = database.begin()->first;
	maxDateLimit = database.end()->first;
}

// TO DO
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	(void) src;
}

BitcoinExchange::~BitcoinExchange(void) {}

// TO DO
BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& src) {
	(void) src;
	return (*this);
}

/* ************************************************************************** */
/*                          PUBLIC MEMBER FUNCTIONS                           */
/* ************************************************************************** */

// ---------------------- Main public member function ----------------------- //
void BitcoinExchange::bitcoinValues(std::string inputFile)
{
	float		value = 0;
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
		if (line == "date | value")
			continue ;
		try {
			checkInputFormat(line);
			date = getDateInEpochTime(line.substr(0, line.find('|') - 1));
			value = getValue(line.substr(line.find('|') + 1, line.size() - 1));
			closestDate = findClosestDate(date);
			printBitcoinValue(closestDate, line.substr(0, 9), value);
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
	float		value = 0;
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
		if (line == "date,exchange_rate")
			continue ;
		try {
			checkInputFormat(line);
			date = getDateInEpochTime(line.substr(0, line.find(',') - 1));
			value = getValue(line.substr(line.find(',') + 1, line.size() - 1));
			database[date] = value;
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
	return (convertToEpochDate(year, month, day));
}

float	BitcoinExchange::getValue(std::string sValue)
{
	checkInputValue(sValue);
	float	value = convertToValue(sValue);
	checkValueValidity(value);
	return (value);
}

time_t	BitcoinExchange::findClosestDate(time_t date)
{
	time_t	diff = -1;
	time_t	closestDate = database.begin()->first - date;

	if (date < minDateLimit)
		throw std::out_of_range("No data before this date.");
	if (date > maxDateLimit)
		return (database[maxDateLimit]);

	for (std::map<time_t, float>::iterator it= database.begin(); it != database.end(); ++it)
    {
		diff = it->first - date;
		if (diff > 0 && diff < closestDate)
			closestDate = it->first;
	}

	return (closestDate);
}

void BitcoinExchange::printBitcoinValue(time_t closestDate, std::string date, float value)
{
	(void) closestDate;
	std::cout	<< date << " => " << value << " = " << value * database[closestDate]
				<< std::endl;
}

// ----------------------------- Date Handling ------------------------------ //

void	BitcoinExchange::checkInputDate(std::string date)
{
	(void) date;
}

void	BitcoinExchange::extractDateInfos(std::string date, int* year, int *month, int* day)
{
	char* 		endptr;

	*year = static_cast<int>(strtol(date.substr(0, 3).c_str(), &endptr, 10));
	*month = static_cast<int>(strtol(date.substr(5, 6).c_str(), &endptr, 10));
	*day = static_cast<int>(strtol(date.substr(8, 9).c_str(), &endptr, 10));
}

void	BitcoinExchange::checkDateValidity(int year, int month, int day)
{
	if (	invalidMonth(month) ||
			invalidDay(month, day) ||
			(!isLeapYear(year) && month == 2 && day > 28) )
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
    return ( (year % 100 != 0) || (year % 400 == 0) );
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

	for (size_t i = 0; i < value.size(); i++)
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
	}
}

float	BitcoinExchange::convertToValue(std::string value)
{
	char* 	endptr;
	return (strtof(value.c_str(), &endptr));
}

void	BitcoinExchange::checkValueValidity(float value) {
	if (value < 0)
		throw std::out_of_range("not a positive number.");
	if (value > 1000)
		throw std::out_of_range("too large a number.");
}
