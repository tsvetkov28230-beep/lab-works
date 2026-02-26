#pragma once

#include "Money.h"

using std::string;

class Account
{
protected:
	static int* instanceCounter;

	int* accountId;
	string* ownerName;
	double* interestRate;
	Money* currentBalance;
public:
	Account();
	Account(string clientName, double rate, Money initialBalance);
	Account(string clientName, double rate, double initialBalance);
	Account(const Account& other);
	Account& operator=(Account& other);
	Account& operator=(Account other);
	~Account();

	void updateOwner(string newOwner);

	bool checkWithdrawalPossible(Money amount);
	bool checkWithdrawalPossible(float amount);

	void processWithdrawal(Money amount);
	void processWithdrawal(float amount);
	void processDeposit(Money amount);
	void processDeposit(float amount);
	void applyInterest();

	double getRubBalance();
	double getUsdBalance();
	double getEurBalance();

};
