#pragma once
#ifndef _CHECKING_ACCOUNT_
#define _CHECKING_ACCOUNT_
#include "Account.h"
using namespace std;

class CheckingAccount : public Account {
	double overDraftLimit;

public:
	void setOverDraftLimit(double _overDraftLimit);
	double getOverDraftLimit() const;

	CheckingAccount();
	CheckingAccount(int _id, double _balance, Customer* _customerAccount, double _overDraftLimit);
};



#endif // !_CHECKING_ACCOUNT_
