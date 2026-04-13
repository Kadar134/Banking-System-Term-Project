#pragma once
#ifndef _CHECKINGACCOUNT_H
#define _CHECKINGACCOUNT_H
#include "Account.h"
using namespace std;

class CheckingAccount: public Account {
	double overDraftLimit = 100;
public:
	//Constructors
	CheckingAccount();
	CheckingAccount(int _id, double _balance, Customer* _customerInfo, double _overDraftLimit);

	//Setter and getter
	void setOverDraftLimit(double _overDraftLimit);
	double getOverDraftLimit() const;
	void setAll(int _id, double _balance, Customer* _customerInfo, double _overDraftLimit);
	
	void withdrawMoney(double amount);
};

#endif //! CHECKINGACCOUNT_H
