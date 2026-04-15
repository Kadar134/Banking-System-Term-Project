#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Customer.h"
using namespace std;

//Account class
class Account {
	int id;
	Customer* accountCustomer;
protected:
	double balance;
	int withdrawalCounter = 0, depositsCounter = 0;
public:
	Account();
	Account(int _id, double _balance, Customer* _accountCustomer);

	//Setters
	void setid(int _id);
	void setAccount(Customer* _accountCustomer);
	void setBalance(double _balance);

	//Getters
	int getid() const;
	Customer* getCustomer() const;
	double getBalance() const;
	int getWithdrawCounter() const;
	int getDepositCounter() const;

	void setAll(int _id, double _balance, Customer* _accountCustomer);

	void depositMoney(double amount);
	void withdrawMoney(double amount);

	void printInfo();
};

#endif // !ACCOUNT_H
