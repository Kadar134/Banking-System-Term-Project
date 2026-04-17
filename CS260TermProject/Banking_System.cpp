#include "CheckingAccount.h"
#include "SavingAccount.h"
#include <iostream>
using namespace std;

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

//Checking Account
void firstOption() {
	string firstName, lastName, address, phone, email;
	/*int ID;
	double balance;*/
	bool looping = true;
	int counter = 0;
	char choice;

	while (looping) {
		cout << "Enter first name: ";
		cin >> firstName;

		cout << "Enter last name: ";
		cin >> lastName;

		cout << "Enter address: ";
		getline(cin, address); //Address needs spaces

		cout << "Enter phone number: ";
		cin >> phone;

		cout << "Enter email: ";
		cin >> email;

		counter++;
		cout << "Do you wish to add another account? (Y/N): ";
		cin >> choice;

		if (choice != 'y' && choice != 'Y')
			looping = false;
	}
	const int SIZE = counter;

	Customer customerList[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		if (phone == customerList[i].getPhone())
		{
			cout << "This account already exists" << endl;
		}
		else
		{
			customerList[i].setAll(firstName, lastName, address, phone, email);
		}
	}
}

	//Saving Account
	void secondOption() {

		int ID;
		double balance, interestRate;
		bool looping = true;
		int counter = 0;
		char choice;

		while (looping) {
			cout << "Enter ID: ";
			cin >> ID;

			cout << "Enter interest rate: ";
			cin >> interestRate;
		
		//pointer for customeraccount?
			counter++;
			cout << "Do you wish to add another saving account? (Y/N): ";
			cin >> choice;

			if (choice != 'y' && choice != 'Y')
				looping = false;
		}
		const int SIZE = counter;

		Customer customerList[SIZE];


	}

int main()
{
	const int SIZE = 50;
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
		case 1:
			firstOption();
			break;
		case 2:
			system("cls");
			secondOption();
			break;
		case 3:
			system("cls");
			cout << "Option 3 Chosen\n";
			break;
		case 4:
			system("cls");
			cout << "Option 4 Chosen\n";
			break;
		case 5:
			system("cls");
			cout << "Option 5 Chosen\n";
			break;
		default:
			system("cls");
			cout << "Invalid option\n";
			break;
		}

		displayMenu();
		cin >> opt;
	}

	cout << "You've chosen to exit the program. Farewell!";
	return 0;
}
// Note: system("cls") will clear the entire screen. Adrian will implement this
