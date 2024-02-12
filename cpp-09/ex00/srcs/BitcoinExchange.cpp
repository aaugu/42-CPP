/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:33:56 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/09 15:53:03 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <ctime>
#include <iostream>
#include <sstream>
#include <fstream>
#include "../includes/BitcoinExchange.hpp"

/* ************************************************************************** */
/*                          ORTHODOX CANONICAL FORM                           */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange(void) {
	// createDatabase("");	
	minDateLimit = database.begin()->first;
	maxDateLimit = database.end()->first;
}

BitcoinExchange::BitcoinExchange(const std::string dataFile) {
	(void) dataFile;
	// createDatabase(dataFile);	
	minDateLimit = database.begin()->first;
	maxDateLimit = database.end()->first;
}

// TO DO
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) { 
	(void) src;
}

// TO DO
BitcoinExchange::~BitcoinExchange(void) {}

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
	float	value = 0;
	time_t	date = 0;
	time_t	closestDate = 0;
	
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
		reinitializeAttributes();
		try {
			value = retrieveDateAndValue(line);
			dateValidityCheck();
			valueValidityCheck(value);
			date = getEpochDate();
			// closestDate = findClosestDate(closestDate, date);
			printBitcoinValue(closestDate, value);
		}
		catch(const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

/* ************************************************************************** */
/*                          PRIVATE MEMBER FUNCTIONS                          */
/* ************************************************************************** */

// ---------------------- Main function sub functions ----------------------- //
void	BitcoinExchange::openFile(std::ifstream* iFS, std::string inputFile)
{
	iFS->open(inputFile, std::fstream::in);
	if (!iFS->good())
		throw BitcoinExchange::OpenFileError();
}

void	BitcoinExchange::reinitializeAttributes(void)
{
	year = 0;
	month = 0;
	day = 0;
}

float	BitcoinExchange::retrieveDateAndValue(std::string line)
{
	if (	line.find('|') > line.size() && 
			line[line.find('|') - 1] == ' ' &&
			line[line.find('|') + 1] == ' ' 	)
		throw BitcoinExchange::BadInput(TYPO, line);

	std::string sDate = line.substr(0, line.find('|') - 1);
	std::string	sValue = line.substr(line.find('|') + 1, line.size() - 1);

	getDate(sDate);
	float	value = getValue(sValue);

	return (value);
}

time_t	BitcoinExchange::findClosestDate(time_t date)
{
	time_t	diff = -1;
	time_t	closestDate = database.begin()->first - date;

	if (date <= minDateLimit)
		return (database[minDateLimit]);
	if (date > maxDateLimit)
		throw std::out_of_range("No data after this date.");

	for (std::map<time_t, float>::iterator it= database.begin(); it != database.end(); ++it)
    {
		diff = it->first - date;
		if (diff > 0 && diff < closestDate)
			closestDate = it->first;
	}

	return (closestDate);
}

void BitcoinExchange::printBitcoinValue(time_t closestDate, float value)
{
	(void) closestDate;
	std::cout	<< year << "-" << month << "-" << day 
				<< " => " << value << " = " /*<< value * database[closestDate]*/
				<< std::endl;
}

// ----------------------------- Line Parsing ------------------------------- //
void	BitcoinExchange::getDate(std::string date)
{
	(void) date;
}

float	BitcoinExchange::getValue(std::string value)
{
	bool	point = false;

	for (size_t i = 0; i < value.size(); i++)
	{
		if (value[i] == '.' && point == false)
		{
			point = true;
			i++;
		}
		else if (value[i] == '.' && point == true)
			throw BitcoinExchange::BadInput(VALUE, "");
		if (std::isdigit(value[i]) == false)
			throw BitcoinExchange::BadInput(VALUE, "");
	}

	char* 	endptr;
	return (strtof(value.c_str(), &endptr));
}

// ----------------------------- Date Handling ------------------------------ //
std::time_t	BitcoinExchange::getEpochDate(void)
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

void		BitcoinExchange::dateValidityCheck(void)
{
	if (	invalidMonth(month) || 
			invalidDay(month, day) || 
			(!isLeapYear(year) && month == 2 && day > 28) )
		{
			throw BitcoinExchange::BadInput(DATE, "");
		}
}

bool BitcoinExchange::isLeapYear(int year) {
    return ( (year % 100 != 0) || (year % 400 == 0) );
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

// ----------------------------- Value Handling ----------------------------- //
void	BitcoinExchange::valueValidityCheck(float value) {
	if (value < 0)
		throw std::out_of_range("not a positive number.");
	if (value > 1000)
		throw std::out_of_range("too large a number.");
}

/* ************************************************************************** */
/*                                EXCEPTIONS                                  */
/* ************************************************************************** */

BitcoinExchange::BadInput::BadInput(int errorType, std::string str)
{
	std::stringstream ss;

	switch (errorType)
	{
	case DATE:
		ss << "bad input => " << year << "-" << month << "-" << day;
		break;
	case VALUE:
		ss << str;
		break;
	case TYPO:
		ss << str;
		break;
	
	default:
		break;
	}

	msg = ss.str();
}

const char*	BitcoinExchange::BadInput::what(void) const throw () {
	return (msg.c_str());
}

const char*	BitcoinExchange::OpenFileError::what(void) const throw () {
	return ("could not open file.");
}