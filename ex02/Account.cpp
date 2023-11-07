/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugu <aaugu@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:58:13 by aaugu             #+#    #+#             */
/*   Updated: 2023/11/07 14:37:55 by aaugu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>

/* ************************************************************************** */
/*                          CONSTRUCTOR & DESTRUCTOR                          */
/* ************************************************************************** */

Account::Account(int initial_deposit)
{
}

Account::~Account(void)
{
}

/* ************************************************************************** */
/*                              PUBLIC FUNCTIONS                              */
/* ************************************************************************** */

void	Account::makeDeposit(int deposit)
{
}

bool	Account::makeWithdrawal(int withdrawal)
{
}

int		Account::checkAmount(void) const
{
}

void	Account::displayStatus(void) const
{
}

static void	Account::displayAccountsInfos( void )
{
}

/* ************************************************************************** */
/*                                  GETTERS                                   */
/* ************************************************************************** */

static int	Account::getNbAccounts(void)
{
}

static int	Account::getTotalAmount(void)
{
}

static int	Account::getNbDeposits(void)
{
}

static int	Account::getNbWithdrawals(void)
{
}

/* ************************************************************************** */
/*                             PRIVATE FUNCTIONS                              */
/* ************************************************************************** */

static void	_displayTimestamp( void )
{
	time_t	now = time(0);
	tm		*ltm = localtime(&now);

	std::cout << "[" << 1900 + ltm->tm_year;
	if (ltm->tm_mon + 1 >= 10)
		std::cout << ltm->tm_mon + 1;
	else
		std::cout << "0" << ltm->tm_mon + 1;
	if (ltm->tm_mday >= 10)
		std::cout << ltm->tm_mday;
	else
		std::cout << "0" << ltm->tm_mday;
	std::cout << "_";
	if (ltm->tm_hour >= 10)
		std::cout << ltm->tm_hour;
	else
		std::cout << "0" << ltm->tm_hour;
	if (ltm->tm_min >= 10)
		std::cout << ltm->tm_min;
	else
		std::cout << "0" << ltm->tm_min;
	if (ltm->tm_sec >= 10)
		std::cout << ltm->tm_sec;
	else
		std::cout << "0" << ltm->tm_sec;
	std::cout << "] ";
	return (0);
}