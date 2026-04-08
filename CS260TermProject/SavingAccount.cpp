#include <iostream>
#include "SavingAccount.h"
using namespace std;

// Constructors - At the beginning for faster code
SavingAccount::SavingAccount() : Account() {
	interestRate = 0;
}

SavingAccount::SavingAccount(int _id, double _balance, Customer* _customerAccount, double _interestRate) : Account(_id, _balance, _customerAccount) {
	if (_interestRate > 0)
		interestRate = _interestRate;
	else
		interestRate = 0;
}

// Setters
void SavingAccount::setInterestRate(double _interestRate) {
	if (_interestRate > 0)
		interestRate = _interestRate;
	else
		interestRate = 0;
}

void SavingAccount::setAll(int _id, double _balance, Customer* _customerAccount, double _interestRate) {
	Account::setAll(_id, _balance, _customerAccount);

	if (_interestRate > 0)
		interestRate = _interestRate;
	else
		interestRate = 0;
}

// Getter
double SavingAccount::getInterestRate() const {
	return interestRate;
}

// fix me later
void SavingAccount::payInterest() {
	double balance;
	balance = getBalance();
	balance = balance + (balance * interestRate);
}

void SavingAccount::transfer(double amount, SavingAccount destinationAccount) {
	// put something here later
}

// Note: there are errors and incomplete code. I will work on this later.
