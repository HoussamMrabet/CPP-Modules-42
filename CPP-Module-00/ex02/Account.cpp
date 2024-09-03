/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:06:37 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/03 20:23:22 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// void Account::_displayTimestamp()
// {
//     int year = 1992;
//     int month = 1;
//     int day = 4;
//     int hour = 9;
//     int minute = 15;
//     int second = 32;

//     std::cout << std::setfill('0') <<"[" << year
//     << std::setw(2) << month
//     <<  std::setw(2) << day
//     <<  "_"
//     <<  std::setw(2) << hour
//     <<  std::setw(2) << minute
//     <<  std::setw(2) << second 
//     << "] ";
// }

void Account::_displayTimestamp()
{
	std::time_t result = std::time(NULL);

	std::cout << std::setfill('0') << "["
	<< 1900 + std::localtime(&result)->tm_year
	<< std::setw(2) << 1 + std::localtime(&result)->tm_mon
	<<  std::setw(2) << std::localtime(&result)->tm_mday
	<<  "_"
	<<  std::setw(2) << std::localtime(&result)->tm_hour
	<<  std::setw(2) << std::localtime(&result)->tm_min
	<<  std::setw(2) << std::localtime(&result)->tm_sec 
	<< "] ";
}

Account::Account(int initial_deposit)
{
	_nbAccounts++;
	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_totalAmount += _amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void    Account::makeDeposit( int deposit )
{
	this->_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	_amount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal )
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbDeposits << std::endl;
	return (true);
}

int  Account::checkAmount( void ) const
{
	return (_amount);
}

void    Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
