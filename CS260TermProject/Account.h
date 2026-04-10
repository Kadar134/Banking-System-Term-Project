#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Customer.h"
using namespace std;

//Account class
class Account {
	int id;
	int withdrawalCounter = 0;
	int depositsCounter = 0;
	Customer* accountCustomer;
protected:
	double balance;
public:
	// Constructors
	Account();
	Account(int _id, double _balance, Customer* _accountCustomer);

	//Setters
	void setid(int _id);
	void setBalance(double _balance);
	void setAccount(Customer* account);
	void setWithDrawCounter(int _withdrawCounter);
	void setDepositCounter(int _depositCounter);
	void setAll(int _id, double _balance, Customer* account);

	//Getters
	int getid() const;
	double getBalance() const;
	Customer* getCustomer() const;
	int getWithdrawCounter() const;
	int getDepositCounter() const;

	// Print
	void printInfo();

	// Deposit & Withdraw
	void depositMoney(double amount);
	void withdrawMoney(double amount);

};

#endif // !ACCOUNT_H
