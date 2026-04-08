#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Customer.h"
using namespace std;

//Account class
class Account {
	int id;
	double balance;
	int withdrawalCounter = 0;
	int depositsCounter = 0;
	Customer* accountCustomer;
public:
	//Setters
	void setid(int _id);
	void setBalance(double _balance);
	void setAccount(Customer* account);
	void setWithDrawCounter(int _withdrawCounter);
	void setDepositCounter(int _depositCounter);

	//Getters
	int getid() const;
	double getBalance() const;
	Customer* getCustomer() const;
	int getWithdrawCounter() const;
	int getDepositCounter() const;

	void setAll(int _id, double _balance, Customer* account);

	void depositMoney(double amount);
	void withdrawMoney(double amount);

	void printInfo();

	Account();
	Account(int _id, double _balance, Customer* _accountCustomer);
};

#endif // !ACCOUNT_H
