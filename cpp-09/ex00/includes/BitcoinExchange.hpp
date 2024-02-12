/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:34:08 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/12 16:29:32 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <ctime>
# include <string>
# include <map>

enum errorTypes { DATE, VALUE, TYPO };

class BitcoinExchange
{
	private:
		std::map<time_t, float>	database;
		time_t	minDateLimit;
		time_t	maxDateLimit;

		// Constructor util function
		void	createDatabase(std::string dataFile);

		// Main function sub functions
		void	openFile(std::ifstream* iFS, std::string inputFile);
		void	checkInputFormat(std::string line);
		time_t	getDateInEpochTime(std::string date);
		float	getValue(std::string value);
		time_t	findClosestDate(time_t date);
		void	printBitcoinValue(time_t closestDate, std::string date, float value);

		// Sub functions utils : Date
		void	checkInputDate(std::string date);
		void	extractDateInfos(std::string date, int* year, int *month, int* day);
		bool	isLeapYear(int year);
		bool	invalidMonth(int month);
		bool	invalidDay(int month, int day);
		void	checkDateValidity(int year, int month, int day);
		time_t	convertToEpochDate(int year, int month, int day);

		// Sub functions utils : Value
		void	checkInputValue(std::string value);
		float	convertToValue(std::string value);
		void	checkValueValidity(float value);

	public:
		// Orthodox Canonical Form
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange(void);
		BitcoinExchange&	operator=(const BitcoinExchange& src);

		// Main public member function
		void	bitcoinValues(std::string inputFile);
};

#endif
