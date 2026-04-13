#include <iostream>
#include "SavingAccount.h"
using namespace std;

// Constructors
SavingAccount::SavingAccount(): Account() {
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

double SavingAccount::getInterestRate() const {
	return interestRate;
}

void SavingAccount::payInterest() {
	balance = balance + (balance * interestRate);
}

void SavingAccount::transfer(double amount, SavingAccount & destinationAccount) {
	if (balance >= amount)
	{
		destinationAccount.balance += amount; //Puts money in new saving account
	}
	else
	{
		cout << "Not enough money to transfer" << endl;
	}


}
