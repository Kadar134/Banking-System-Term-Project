#pragma once
#include <string>
#include <iomanip>
#include "Account.h"
using namespace std;

#ifndef _CHECKING_ACCOUNT_
#define _CHECKING_ACCOUNT_

// CheckingAccount class
class CheckingAccount : Account {
	double overDraftLimit;

public:
	CheckingAccount() : Account() {
		overDraftLimit = 0;
	}

	CheckingAccount(double limit, int _id, double _balance, Customer* account) : Account(_id, _balance, account) {
		if (limit >= 0)
			overDraftLimit = limit;
		else
			overDraftLimit = 0;
	}

	void setLimit(double limit) {
		if (limit >= 0)
			overDraftLimit = limit;
		else
			overDraftLimit = 0;
	}

	double getLimit() {
		return overDraftLimit;
	}

	void setAll(double limit, int _id, double _bal, Customer* account) {
		if (limit >= 0)
			overDraftLimit = limit;
		else
			overDraftLimit = 0;
		
		Account::setall(_id, _bal, account);
	}


};


#endif // !_CHECKING_ACCOUNT_
