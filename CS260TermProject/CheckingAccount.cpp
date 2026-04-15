#include <iostream>
#include "CheckingAccount.h"
using namespace std;

CheckingAccount::CheckingAccount() : Account()
{
	overDraftLimit = 0;
}

CheckingAccount::CheckingAccount(int _id, double _balance, Customer* _customerInfo, double _overDraftLimit) : Account(_id, _balance, _customerInfo)
{
	if (overDraftLimit < 0)
	{
		overDraftLimit = 0;
	}
	else
	{
		overDraftLimit = _overDraftLimit;
	}
}

void CheckingAccount::setOverDraftLimit(double _overDraftLimit)
{
	if (overDraftLimit < 0)
	{
		overDraftLimit = 0;
	}
	else
	{
		overDraftLimit = _overDraftLimit;
	}
}

double CheckingAccount::getOverDraftLimit() const
{
	return overDraftLimit;
}

void CheckingAccount::setAll(int _id, double _balance, Customer* _customerInfo, double _overDraftLimit)
{
	Account::setAll(_id, _balance, _customerInfo);
	if (overDraftLimit < 0)
	{
		overDraftLimit = 0;
	}
	else
	{
		overDraftLimit = _overDraftLimit;
	}
}

void CheckingAccount::withdrawMoney(double amount)
{
	if (amount < 0) //Makes sure the amount you want to withdrawal is enough
	{
		amount = 0;
	}
	else
	{
		if (balance >= amount) //If what you have in the bank is more than or equal to the amount
		{
			balance = balance - amount; //Updates balance
			withdrawalCounter++;
		}
		else
		{
			if (balance <= overDraftLimit) //If what you have in the bank is below 0 but you're using overdraft
			{
				balance = balance - overDraftLimit;
				if (overDraftLimit < 0)
				{
					cout << "Overdraft limit has run out" << endl;
				}
				else
				{
					overDraftLimit = overDraftLimit - 20;
				}
				withdrawalCounter++;
			}
			else //If you don't have enough in your overdraft
			{
				cout << "Cannot use overdraft" << endl;
			}
		}
	}
}
