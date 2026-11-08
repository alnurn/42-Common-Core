/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurmach <anurmach@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:13:47 by anurmach          #+#    #+#             */
/*   Updated: 2026/10/10 12:27:12 by anurmach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_displayTimestamp();
	_accountIndex = getNbAccounts();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";" << "created" << std::endl;
	_nbAccounts++;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}


void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}


void	Account::_displayTimestamp(void)
{
	time_t		now;
	struct tm	*Now;

	now = std::time(NULL);
	Now = std::localtime(&now);
	std::cout << "[" << Now->tm_year + 1900;
	if (Now->tm_mon + 1 > 9)
		std::cout << Now->tm_mon + 1;
	else
		std::cout << "0" << Now->tm_mon + 1;
	if (Now->tm_mday > 9)
		std::cout << Now->tm_mday;
	else
		std::cout << "0" << Now->tm_mday;
	std::cout << "_";
	if (Now->tm_hour > 9)
		std::cout << Now->tm_hour;
	else
		std::cout << "0" << Now->tm_hour;
	if (Now->tm_min > 9)
		std::cout << Now->tm_min;
	else
		std::cout << "0" << Now->tm_min;
	if (Now->tm_sec > 9)
		std::cout << Now->tm_sec;
	else
		std::cout << "0" << Now->tm_sec;
	std::cout << "] ";
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	_nbDeposits++;
	_totalNbDeposits++;
	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}


bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = checkAmount();
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "withdrawal:";
	if (p_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return (true);
}
