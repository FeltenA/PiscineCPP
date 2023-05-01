#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(this->_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    this->_nbAccounts++;
    this->_totalAmount += this->_amount;
    this->_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account(void) : _accountIndex(this->_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {
    this->_nbAccounts++;
}

Account::~Account(void) {
    this->_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
    return (_nbAccounts);
}

int Account::getNbDeposits(void) {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (_totalNbWithdrawals);
}

int Account::getTotalAmount(void) {
    return (_totalAmount);
}

void    Account::_displayTimestamp(void) {
    std::time_t time = std::time(0);
    std::tm *ltime = localtime(&time);
    std::cout << "[" << std::setfill('0') << std::setw(4) << ltime->tm_year + 1900;
    std::cout << std::setfill('0') << std::setw(2) << ltime->tm_mon + 1;
    std::cout << std::setfill('0') << std::setw(2) << ltime->tm_mday << "_";
    std::cout << std::setfill('0') << std::setw(2) << ltime->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << ltime->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << ltime->tm_sec << "]";
}

void    Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:";
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    std::cout << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if (this->_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

void    Account::displayStatus(void) const {
    this->_displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}