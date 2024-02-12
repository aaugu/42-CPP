/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:34:08 by aaugu             #+#    #+#             */
/*   Updated: 2024/02/09 15:56:54 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
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
		static int		year;
		static int		month;
		static int		day;

		// Main function sub functions : Utils
		void	openFile(std::ifstream* iFS, std::string inputFile);
		void	reinitializeAttributes(void);
		float	retrieveDateAndValue(std::string line);
		time_t	findClosestDate(time_t date);
		void	printBitcoinValue(time_t closestDate, float value);

		// Main function sub functions : Line Parsing
		void	getDate(std::string date);
		float	getValue(std::string value);

		// Main function sub functions : Date Handling
		void	dateValidityCheck(void);
		time_t	getEpochDate(void);
		bool	isLeapYear(int year);
		bool	invalidMonth(int month);
		bool	invalidDay(int month, int day);

		// Main function sub functions : Value Handling
		void	valueValidityCheck(float value);

	public:
		// Orthodox Canonical Form
		BitcoinExchange(void);
		BitcoinExchange(const std::string dataFile);
		BitcoinExchange(const BitcoinExchange& src);
		~BitcoinExchange(void);
		BitcoinExchange&	operator=(const BitcoinExchange& src);

		// Main public member function
		void	bitcoinValues(std::string inputFile);

		// Exceptions
		class OpenFileError : public std::exception {
			public:
				virtual const char *	what(void) const throw ();
		};

		class BadInput : public std::exception {
			private:
				std::string	msg;

			public:
				BadInput(int errorType, std::string str);
				virtual const char *	what(void) const throw ();
		};


};

#endif
