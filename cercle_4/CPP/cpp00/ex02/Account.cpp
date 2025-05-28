/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daavril <daavril@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:11:25 by daavril           #+#    #+#             */
/*   Updated: 2025/05/27 13:25:57 by daavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << Account::checkAmount()
				<< ";created"
				<< std::endl;
	return ;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << Account::checkAmount()
				<< ";closed"
				<< std::endl;
	return ;
}

//getter checkAmount, permet de regarder la valeur
//d'un membre private de la classe
//meme si c'est possible d faire this->_amount
//on appel ca de l'"encapsulation"
int	Account::checkAmount(void) const
{
	return (this->_amount);
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

void	Account::_displayTimestamp(void)
{
	//get l'heure actuelle du systeme
	time_t	now = time(NULL);
	//la convertir en struct tm
	tm		*time = localtime(&now);
	
	std::cout << "["
				<< 1900 + time->tm_year
				<< std::setw(2) << std::setfill('0') << time->tm_mon + 1
				<< std::setw(2) << std::setfill('0') <<time->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') <<time->tm_hour
				<< std::setw(2) << std::setfill('0') <<time->tm_min
				<< std::setw(2) << std::setfill('0') <<time->tm_sec
				<< "] ";
	return ;
}

//methode de classe (static) , n'a pas de pointeur this->
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount()
				<< ";deposit:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

//methode d'instance/membre de la classe
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << Account::checkAmount()
				<< ";deposit:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << Account::checkAmount()
				<< ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << Account::checkAmount();
	this->_nbDeposits++;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << Account::checkAmount();
	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
		std::cout << ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	std::cout << ";amount:" << Account::checkAmount();
	this->_nbWithdrawals++;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return (true);
}

//initialisation des varaible non membres de la classe
//a decrementer dans le destructeur
//car on peut les enlever
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
//ne pas decrementer car garde un historique
//une fois un depot ou un retrait fait on ne peut pas
//l'enlever
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
