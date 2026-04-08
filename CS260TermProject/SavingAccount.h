#pragma once
#ifndef _SAVINGS_ACCOUNT_
#define _SAVINGS_ACCOUNT_
#include "Account.h"
using namespace std;

class SavingAccount : Account {
	double interestRate;

public:
	// Constructors
	SavingAccount();
	SavingAccount(int _id, double _balance, Customer* _customerAccount, double _interestRate);

	// Setters and Getters
	void setInterestRate(double _interestRate);
	void setAll(int _id, double _balance, Customer* _customerAccount, double _interestRate);
	double getInterestRate() const;

	// Specs
	void payInterest();
	void transfer(double amount, SavingAccount destinationAccount);
};

#endif // !_SAVINGS_ACCOUNT_

// Header file is complete.
