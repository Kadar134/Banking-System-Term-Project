#include <iostream>
#include "Customer.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
using namespace std;

// Prototype zone
void firstOption();
void secondOption();
void thirdOption();
void fourthOption();
void fifthOption();

// Menu
void displayMenu() {
	cout << "- MAIN MENU -" << endl;
	cout << "1. Create Checking Account" << endl;
	cout << "2. Create Saving Account" << endl;
	cout << "3. View Account Information" << endl;
	cout << "4. Modify Your Account" << endl;
	cout << "5. Transfer Money" << endl;
	cout << "6. Exit" << endl;

	cout << "Enter an option (1-6): ";
}

int main()
{
	int opt;
	displayMenu();
	cin >> opt;

	while (opt < 1 || opt > 6) //Checks if option is valid
	{
		cout << "Invalid option" << endl << endl;
		displayMenu();
		cin >> opt;
	}
	while (opt != 6)
	{
		switch (opt)
		{
		case 1: //Create a checking account
		{
			firstOption();
			break;
		}

		case 2: //Creating a saving account
			secondOption();
			break;
		case 3: // viewing account information
			thirdOption();
			break;
		case 4: //Modifying/deleting
			fourthOption();
			break;
		case 5: //Transferring between accounts
			fifthOption();
			break;
		default:
			cout << "Invalid option\n";
			break;
		}

		displayMenu();
		cin >> opt;
	}

	cout << "You've chosen to exit the program. Farewell!";
	return 0;
}
	cout << "You've chosen to exit the program. Farewell!";
	return 0;
}

void firstOption() {
	const int SIZE = 20;
	Customer customerList[SIZE];
	int customerIndex = 0;

	CheckingAccount checkingArr[SIZE];
	int checkingIndex = 0;

	int ID;
	double balance, overdraft;
	string firstName, lastName, address, phone, email;
	bool checking;

	cout << "Enter first name: ";
	cin >> firstName;

	cout << "Enter last name: ";
	cin >> lastName;

	cout << "Enter address: ";
	cin.ignore();
	getline(cin, address); //Address needs spaces

	cout << "Enter phone number: ";
	cin >> phone;

	do
	{
		checking = false;
		for (int i = 0; i < customerIndex; i++)
		{
			if (phone == customerList[i].getPhone())
			{
				checking = true;
				cout << "This account already exists. Enter a different phone number: ";
				cin >> phone;
				break;
			}
		}
	} while (checking);

	cout << "Enter email: ";
	cin >> email;

	customerList[customerIndex].setAll(firstName, lastName, address, phone, email);

	cout << "Enter balance: ";
	cin >> balance;

	cout << "Set overdraft limit: ";
	cin >> overdraft;

	ID = customerIndex + 1;
	checkingArr[checkingIndex].setAll(ID, balance, &customerList[customerIndex], overdraft);

	customerIndex++;
	checkingIndex++;
	cout << endl;
}

void secondOption() {
	const int SIZE = 20;
	SavingAccount savingArr[SIZE];
	int savingIndex = 0;
}

void thirdOption() { // Fix
	cout << "ACCOUNT INFORMATION" << endl;

}

void fourthOption() {

}

void fifthOption() {

}
