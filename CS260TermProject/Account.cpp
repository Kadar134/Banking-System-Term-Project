#include <iostream>
#include <iomanip>
#include "Customer.h"
#include "Account.h"
using namespace std;

//Not initialziing these in the header file because that doesn't work
int Account::withdrawalCounter = 0; 
int Account::depositsCounter = 0;

void Account::setid(int _id) 
{
	if (_id < 0)
	{
		id = 0;
	}
	else
	{
		id = _id;
	}
}

void Account::setBalance(double _balance) 
{
	if (_balance < 0)
	{
		balance = 0;
	}
	else
	{
		balance = _balance;
	}
}

void Account::setWithDrawCounter(int _withdrawCounter)
{
	withdrawalCounter = _withdrawCounter;
	
}

void Account::setDepositCounter(int _depositCounter)
{
	depositsCounter = _depositCounter;
}

void Account::setAccount(Customer* account) { 
	accountCustomer = account;
}

int Account::getid() const {
	return id;
}

double Account::getBalance() const {
	return balance;
}

int Account::getWithdrawCounter() const {
	return withdrawalCounter;
}

int Account::getDepositCounter() const {
	return depositsCounter;
}

Customer* Account::getCustomer() const {
	return accountCustomer;
}

//Default
Account::Account() {
	id = 0;
	balance = 0;
	withdrawalCounter = 0;
	depositsCounter = 0;
}

//Parameterized
Account::Account(int _id, double _balance) 
{
	if (_id < 0)
	{
		id = 0;
	}
	else
	{
		id = _id;
	}
	
	if (_balance < 0)
	{
		balance = 0;
	}
	else
	{
		balance = _balance;
	}

	//These are set to 0 because they're counters
	withdrawalCounter = 0; 
	depositsCounter = 0;
}


void Account::setAll(int _id, double _balance, Customer* account) 
{
	if (_id < 0)
	{
		id = 0;
	}
	else
	{
		id = _id;
	}
	balance = _balance;
	accountCustomer = account;
	//No reason to set the counters to 0 because you're not manually setting those to anything
}


void Account::depositMoney(double amount) {
	if (amount < 0)
	{
		balance += 0;
	}
	else
	{
		balance += amount;
		depositsCounter++; //Updates the deposit counter
	}
}

void Account::withdrawMoney(double amount) {
	if (amount > 0) {
		if (amount <= balance)
		{
			balance -= amount;
			withdrawalCounter++; //Updates the withdraw counter
		}
		else
			cout << "Insufficient funds." << endl;
	}
	else
		balance -= 0;
}


void Account::printInfo() {
	cout << "Retrieved Banking Information for: ";
	cout << accountCustomer->getFname() << " " << accountCustomer->getLname() << endl;

	accountCustomer->PrintInfo();
	cout << "Bank ID: " << id << endl;

	cout << "Current Balance: $";
	cout << fixed << showpoint << setprecision(2) << balance << endl;

	cout << "Withdraws Made: " << withdrawalCounter << endl;
	cout << "Deposits Made: " << depositsCounter << endl;
}
