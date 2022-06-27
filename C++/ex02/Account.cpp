/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalvemi <asalvemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:08:47 by asalvemi          #+#    #+#             */
/*   Updated: 2022/06/27 20:08:50 by asalvemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <chrono>
#include "Account.hpp" 

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = this->_nbAccounts++;
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << initial_deposit << ";";
    std::cout << "created" << std::endl;
}

Account::Account()
{
    this->_accountIndex = this->_nbAccounts++;
    this->_amount = 0;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:0;";
    std::cout << "created" << std::endl;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    this->_nbAccounts--;
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

int     Account::getNbAccounts(void)
{
    return(Account::_nbAccounts);
}

int     Account::getTotalAmount(void)
{
    return(Account::_totalAmount);
}

int     Account::getNbDeposits(void)
{
    return(Account::_totalNbDeposits);
}

int     Account::getNbWithdrawals(void)
{
    return(Account::_totalNbWithdrawals);
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "p_amount:" << Account::_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    if (deposit > 0)
    {
        Account::_amount += deposit;
        Account::_totalAmount += deposit;
        std::cout << "amount:" << Account::_amount << ";";
        Account::_nbDeposits++;
        Account::_totalNbDeposits++;
        std::cout << "nb_deposit:" << Account::_nbDeposits << std::endl;
    }
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "p_amout:" << Account::_amount << ";";
    if (this->_amount < withdrawal)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
        std::cout << "withdrawal:" << withdrawal  << ";";
        Account::_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        std::cout << "amount" << Account::_amount << ";";
        Account::_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        std::cout << "nb_withdrawal" << Account::_nbWithdrawals << std::endl;
        return (true);
    }
    return (false);
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int     Account::checkAmount(void) const
{
    return (this->_amount > 0);
}

void    Account::_displayTimestamp(void)
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t time_now = std::chrono::system_clock::to_time_t(now);

	tm utc_tm = *localtime(&time_now);
	std::cout << std::setfill('0') << "[" << (utc_tm.tm_year + 1900)
			<< std::setw(2) << utc_tm.tm_mon
			<< std::setw(2) << utc_tm.tm_mday << "_"
			<< std::setw(2) << utc_tm.tm_hour
			<< std::setw(2) << utc_tm.tm_min
			<< std::setw(2) << utc_tm.tm_sec << "] ";
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}