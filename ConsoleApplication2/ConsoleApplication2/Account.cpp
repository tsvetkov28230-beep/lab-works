#include "Account.h"

const double RUB_TO_USD = 80.97;
const double RUB_TO_EUR = 94.08;

int* Account::instanceCounter = new int(0);

Account::Account()
{
    accountId = new int((*instanceCounter)++);
    ownerName = new string();
    interestRate = new double(0);
    currentBalance = new Money();
}

Account::Account(string clientName, double rate, Money initialBalance)
{
    accountId = new int((*instanceCounter)++);
    ownerName = new string(clientName);
    interestRate = new double(rate);
    currentBalance = new Money(initialBalance);
}

Account::Account(string clientName, double rate, double initialBalance)
{
    accountId = new int((*instanceCounter)++);
    ownerName = new string(clientName);
    interestRate = new double(rate);
    currentBalance = new Money(initialBalance);
}

Account::Account(const Account& other) {
    accountId = new int((*instanceCounter)++);
    ownerName = new string(*other.ownerName);
    interestRate = new double(*other.interestRate);
    currentBalance = new Money(*other.currentBalance);
}

Account& Account::operator=(Account& other) {
    if (this != &other) {
        *accountId = *other.accountId;
        *ownerName = *other.ownerName;
        *interestRate = *other.interestRate;
        *currentBalance = *other.currentBalance;
    }
    return *this;
}

Account& Account::operator=(Account other) {
    if (this != &other) {
        *accountId = *other.accountId;
        *ownerName = *other.ownerName;
        *interestRate = *other.interestRate;
        *currentBalance = *other.currentBalance;
    }
    return *this;
}

Account::~Account() {
    delete accountId;
    delete ownerName;
    delete interestRate;
    delete currentBalance;
}

void Account::updateOwner(string newOwner)
{
    *ownerName = newOwner;
}

bool Account::checkWithdrawalPossible(Money amount)
{
    return *currentBalance >= amount;
}

bool Account::checkWithdrawalPossible(float amount)
{
    return currentBalance->toDouble() >= amount;
}

void Account::processWithdrawal(Money amount)
{
    if (checkWithdrawalPossible(amount)) {
        *currentBalance = *currentBalance - amount;
    }
}

void Account::processWithdrawal(float amount)
{
    Money withdrawalAmount = Money(amount);
    if (checkWithdrawalPossible(withdrawalAmount)) {
        *currentBalance = *currentBalance - amount;
    }
}

void Account::processDeposit(Money amount)
{
    *currentBalance = *currentBalance + amount;
}

void Account::processDeposit(float amount)
{
    *currentBalance = *currentBalance + amount;
}

void Account::applyInterest()
{
    *currentBalance = *currentBalance * (1 + *interestRate);
}

double Account::getRubBalance()
{
    return currentBalance->toDouble();
}

double Account::getUsdBalance()
{
    return currentBalance->toDouble() / RUB_TO_USD;
}

double Account::getEurBalance()
{
    return currentBalance->toDouble() / RUB_TO_EUR;
}