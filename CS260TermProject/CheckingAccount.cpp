#include "CheckingAccount.h"
#include <iomanip>
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount() : Account() {
	overDraftLimit = 0;
}

CheckingAccount::CheckingAccount(int _id, double _balance, Customer* _customerAccount, double _overDraftLimit) : Account(_id, _balance, _customerAccount) {
	if (_overDraftLimit >= 0)
		overDraftLimit = _overDraftLimit;
	else
		overDraftLimit = 0;
}

void CheckingAccount::setOverDraftLimit(double _overDraftLimit) {
	if (_overDraftLimit >= 0)
		overDraftLimit = _overDraftLimit;
	else
		overDraftLimit = 0;
}

double CheckingAccount::getOverDraftLimit() const {
	return overDraftLimit;
}
