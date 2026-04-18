#include <iostream>
#include "Customer.h"
#include "CheckingAccount.h"
#include "SavingAccount.h"
using namespace std;

// Prototype zone
void firstOption(const int SIZE, Customer customerList[], int customerIndex, CheckingAccount checkingArr[], int checkingIndex);
void secondOption(const int SIZE, Customer customerList[], int customerIndex, SavingAccount savingArr[], int savingIndex);
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
	const int SIZE = 20;
	Customer customerList[SIZE];
	int customerIndex = 0;
	CheckingAccount checkingArr[SIZE];
	int checkingIndex = 0;
	SavingAccount savingArr[SIZE];
	int savingIndex = 0;

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
			firstOption(SIZE, customerList, customerIndex, checkingArr, checkingIndex);
			break;
		}

		case 2:
		{
			//Creating a saving account
			secondOption(SIZE, customerList, customerIndex, savingArr, savingIndex);
			break;
		}
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

void firstOption(const int SIZE, Customer customerList[], int customerIndex, CheckingAccount checkingArr[], int checkingIndex) {
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

void secondOption(const int SIZE, Customer customerList[], int customerIndex, SavingAccount savingArr[], int savingIndex)
{ // Temp code, fix momentarily. IMMMM fixing it momentarily. Dont touch my child code.
	
	// temporary values for debugging - CHANGE WHEN GLOBAL...ER
	customerList[customerIndex].setAll("Reza", "Sarraf", "2800 University Blvd. N.", "34983535", "rsarraf@jacksonville.edu");

	double balance, interestRate;
	int ID;

	cout << "Enter balance: ";
	cin >> balance;

	cout << "What is the interest rate?: ";
	cin >> interestRate;

	ID = savingIndex + 1;

	savingArr[savingIndex].setAll(ID, balance, &customerList[customerIndex], interestRate);
	savingIndex++;
	customerIndex++;
	cout << endl;
}

void thirdOption() { // Fix
	cout << "ACCOUNT INFORMATION" << endl;

}

void fourthOption() {

}

void fifthOption() { // Adrian is doing this don't touch it's my redemption arc 

}
