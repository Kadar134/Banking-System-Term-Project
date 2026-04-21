#include "CheckingAccount.h"
#include "SavingAccount.h"
#include "Customer.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Prototype zone
// change the option names
void createChecking(const int SIZE, Customer customerList[], int& customerIndex, CheckingAccount checkingArr[], int& checkingIndex);
void createSaving(const int SIZE, Customer customerList[], int& customerIndex, SavingAccount savingArr[], int& savingIndex);
void viewAccountInfo(const int SIZE, Customer customerList[], int customerIndex, CheckingAccount checkingArr[], int checkingIndex, SavingAccount savingArr[], int savingIndex);
void modifyAccount(const int SIZE, Customer customerList[], int& customerIndex, CheckingAccount checkingArr[], int& checkingIndex, SavingAccount savingArr[], int& savingIndex);
void transferSavingAccount(const int SIZE, Customer customerList[], int& customerIndex, SavingAccount savingArr[], int& savingIndex);
void withdraw(const int SIZE, Customer customerList[], int& customerIndex, CheckingAccount checkingArr[], int& checkingIndex);

// Menu
int displayMenu() { //Is value returning so we can return opt
	int opt = 0;
	cout << "- MAIN MENU -" << endl;
	cout << "1. Create Checking Account" << endl;
	cout << "2. Create Saving Account" << endl;
	cout << "3. View Account Information" << endl;
	cout << "4. Modify Your Account" << endl;
	cout << "5. Internal Transfer Between Savings Accounts" << endl;
	cout << "6. Withdraw Money" << endl;
	cout << "7. Deposit Money" << endl;
	cout << "8. Exit" << endl;

	cout << "Enter an option (1-8): ";
	cin >> opt;
	while (opt < 1 || opt > 8)
	{
		//The menu is reprinted only if the user types the wrong value
		cout << "Invalid! Please enter an option between 1-8: ";
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cin >> opt; //Put outside the loop for if the cin didn't fail
	}
	return opt;
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
	
	// prompt to add a user

	int opt = displayMenu(); //Saves the option the user chose

	while (opt < 1 || opt > 8) //Checks if option is valid
	{
		cout << "Invalid option" << endl << endl;
		opt = displayMenu(); //Makes it so that whatever the user types in the menu gets turned into an option and goes in the loop
	}
	while (opt != 8)
	{
		switch (opt)
		{
		case 1: //Create a checking account
		{
			createChecking(SIZE, customerList, customerIndex, checkingArr, checkingIndex);
			break;
		}

		case 2:
		{
			//Creating a saving account
			createSaving(SIZE, customerList, customerIndex, savingArr, savingIndex);
			break;
		}
		case 3: // viewing account information
			viewAccountInfo(SIZE, customerList, customerIndex, checkingArr, checkingIndex, savingArr, savingIndex);
			break;

		case 4: // Modifying/deleting
			modifyAccount(SIZE, customerList, customerIndex, checkingArr, checkingIndex, savingArr, savingIndex);
			break;

		case 5: // Transferring  accounts (internal)
			transferSavingAccount(SIZE, customerList, customerIndex, savingArr, savingIndex);
			break;

		case 6: // Withdraw Money
			double withdrawAmount;
			cout << "Enter an amount to withdraw: ";
			cin >> withdrawAmount;
			if (withdrawAmount > 0)
				withdraw(SIZE, customerList, customerIndex, checkingArr, checkingIndex);
			else
				cout << "Invalid input." << endl;
			break;

		case 7: // Deposit Money
			cout << "nothing to see here gang" << endl;
			break;

		default:
			cout << "Invalid option\n";
			break;
		}
		opt = displayMenu(); //Reprinted from previous while loop
	}

	cout << "You've chosen to exit the program. Farewell!";
	return 0;
}

void createChecking(const int SIZE, Customer customerList[], int& customerIndex, CheckingAccount checkingArr[], int& checkingIndex) {
	string firstName, lastName, address, phone, email;
	bool checking;
	int ID;
	double balance, overdraft;

	if (customerIndex >= SIZE)
	{
		cout << "Too many accounts" << endl;
	}
	else
	{
		cout << "Enter first name: ";
		cin >> firstName;

		cout << "Enter last name: ";
		cin >> lastName;

		cout << "Enter address: ";
		cin.ignore(1000, '\n');
		getline(cin, address); //Address needs spaces

		cout << "Enter phone number: ";
		cin >> phone;

		while (phone.length() != 10) //Makes sure the phone numbers use 10 digits
		{
			cout << "Need to pass a number exactly 10 digits in length. Please try again: ";
			cin >> phone;
		}

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
		
		ID = customerIndex + 1;
		cout << "ID is " << ID << endl;
		
		cout << "Enter balance: ";
		cin >> balance;
		while (cin.fail()) //Validates if balance uses letters
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Need to use numbers. Enter balance: ";
			cin >> balance;
		}

		cout << "Enter overdraft limit: ";
		cin >> overdraft;

		while (cin.fail()) //Validates if overdraft uses letters
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Need to use numbers. Enter overdraft: ";
			cin >> overdraft;
		}

		checkingArr[checkingIndex].setAll(ID, balance, &customerList[customerIndex], overdraft);

		customerIndex++;
		checkingIndex++;
		cout << endl;
	}
}

void createSaving(const int SIZE, Customer customerList[], int& customerIndex, SavingAccount savingArr[], int& savingIndex)
{
	string firstName, lastName, address, phone, email;
	bool checking;
	int ID;
	double balance, interestRate;

	cout << "Enter first name: ";
	cin >> firstName;

	cout << "Enter last name: ";
	cin >> lastName;

	cout << "Enter address: ";
	cin.ignore(1000, '\n');
	getline(cin, address); //Address needs spaces

	cout << "Enter phone number: ";
	cin >> phone;

	while (phone.length() != 10) //Makes sure the phone numbers use 10 digits
	{
		cout << "Need to pass a number exactly 10 digits in length. Please try again: ";
		cin >> phone;
	}

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

	ID = customerIndex + 1;
	cout << "ID is " << ID << endl;

	cout << "Enter balance: ";
	cin >> balance;
	while (cin.fail()) //Validates if balance uses letters
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Need to use numbers. Enter balance: ";
		cin >> balance;
	}

	cout << "Enter interest rate: ";
	cin >> interestRate;

	while (cin.fail()) //Validates if interest rate uses letters
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Need to use numbers. Enter interest rate: ";
		cin >> interestRate;
	}
	
	savingArr[savingIndex].setAll(ID, balance, &customerList[customerIndex], interestRate);

	customerIndex++;
	savingIndex++;
	cout << endl;
}

void viewAccountInfo(const int SIZE, Customer customerList[], int customerIndex, CheckingAccount checkingArr[], int checkingIndex, SavingAccount savingArr[],
	int savingIndex) { //Views account information

	if (checkingIndex < 1) //Makes it so the user can't view accounts that haven't been added yet
	{
		cout << "No accounts have been made. Please try again." << endl << endl;
	}
	else
	{
		char accountType;
		cout << "Do you want to view checking or savings? (Type C or S): ";
		cin >> accountType;

		if (accountType == 'C' || accountType == 'c')
		{
			for (int i = 0; i < checkingIndex; i++)
			{
				cout << endl << "Viewing Account " << i + 1 << endl;
				customerList[i].printInfo();
				cout << "ID: " << checkingArr[i].getid() << endl;
				cout << "Balance: " << checkingArr[i].getBalance() << endl;
				cout << "Overdraft limit: " << checkingArr[i].getOverDraftLimit() << endl;
				cout << "------------------------------------------" << endl << endl;
			}
		}
		else if (accountType == 'S' || accountType == 's')
		{
			for (int i = 0; i < savingIndex; i++)
			{
				cout << endl << "Viewing Account " << i + 1 << endl;
				customerList[i].printInfo();
				cout << "ID: " << savingArr[i].getid() << endl;
				cout << "Balance: " << savingArr[i].getBalance() << endl;
				cout << "Interest rate: " << savingArr[i].getInterestRate() << endl;
				cout << "------------------------------------------" << endl << endl;
			}
		}
		else
		{
			cout << "You didn't type C or S. Please try again" << endl;
		}
	}
}

void modifyAccount(const int SIZE, Customer customerList[], int& customerIndex, CheckingAccount checkingArr[], int& checkingIndex, SavingAccount savingArr[], int& savingIndex) { // modify/delete
	if (checkingIndex < 1) {
		cout << "No account has been made." << endl;
	}
	
	else {
		char choice;

		cout << "OPTIONS" << endl;
		cout << "1. Modify an account" << endl;
		cout << "2. Delete an account" << endl;
		cout << "3. Back to main menu" << endl;
		cout << "Select a menu option (1-3): ";
		cin >> choice;
		cout << endl;

		while (choice != '3') {
			if (choice == '1') { // MODIFICATION
				char accountChoice;

				cout << "MODIFY ACCOUNT" << endl;
				cout << "1. Customer Information" << endl;
				cout << "2. Checking Accounts" << endl;
				cout << "3. Saving Accounts" << endl;
				cout << "4. Go Back" << endl;
				cout << "Select a menu option (1-4): ";
				cin >> accountChoice;
				cout << endl;

				while (accountChoice != '4') {
					if (accountChoice == '1') {
						char modifyCustomerChoice;

						cout << "CUSTOMER DETAILS" << endl;
						customerList[customerIndex].printInfo();
						cout << endl;

						cout << "MODIFY CUSTOMER" << endl;
						cout << "1. Customer Name" << endl;
						cout << "2. Home Address" << endl;
						cout << "3. Phone Number" << endl;
						cout << "4. Email Address" << endl;
						cout << "5. Go Back" << endl;
						cout << "What would you like to modify? (1-5): ";
						cin >> modifyCustomerChoice;
						cout << endl;

						while (modifyCustomerChoice != '5') {

							if (modifyCustomerChoice == '1') {
								string fname, lname;

								cout << "Enter first name: ";
								cin >> fname;

								cout << "Enter last name: ";
								cin >> lname;

								customerList[customerIndex].setFname(fname);
								customerList[customerIndex].setLname(lname);

								cout << "Name updated." << endl;
								cout << endl;
							}

							else if (modifyCustomerChoice == '2') {
								string homeAddress;

								cout << "Enter home address: ";
								cin.ignore();
								getline(cin, homeAddress);

								customerList[customerIndex].setAddress(homeAddress);

								cout << "Home address updated." << endl;
								cout << endl;
							}

							else if (modifyCustomerChoice == '3') {
								string phone, verify; // phone numbers can easily be mistyped

								cout << "Enter phone number: ";
								cin >> phone;

								cout << "Verify phone number: ";
								cin >> verify;

								if (phone == verify) {
									customerList[customerIndex].setPhone(phone);
									cout << "Phone number updated." << endl;
								}
								else
									cout << "Input numbers do not match." << endl;
								cout << endl;
							}

							else if (modifyCustomerChoice == '4') {
								string email, verify; // emails can easily be mistyped

								cout << "Enter email address: ";
								cin >> email;

								cout << "Verify email address: ";
								cin >> verify;

								if (email == verify) {
									customerList[customerIndex].setEmail(email);
									cout << "Email address updated." << endl;
								}
								else
									cout << "Input emails do not match." << endl;
								cout << endl;
							}

							else {
								cout << "Invalid input." << endl;
								cout << endl;
							}

							cout << "CUSTOMER DETAILS" << endl;
							customerList[customerIndex].printInfo();
							cout << endl;

							cout << "MODIFY CUSTOMER" << endl;
							cout << "1. Customer Name" << endl;
							cout << "2. Home Address" << endl;
							cout << "3. Phone Number" << endl;
							cout << "4. Email Address" << endl;
							cout << "5. Go Back" << endl;
							cout << "What would you like to modify? (1-5): ";
							cin >> modifyCustomerChoice;
							cout << endl;
						}
					}

					else if (accountChoice == '2') { // Fix this to include multiple checking accounts.
						cout << "CHECKING ACCOUNT INFORMATION" << endl;
						checkingArr[checkingIndex].printInfo(); // overdraft
						cout << endl;

						char checkingSelection;
						cout << "MODIFY CHECKING ACCOUNT" << endl;
						cout << "1. Overdraft Limit" << endl;
						cout << "2. Go Back" << endl;
						cout << "What would you like to modify? (1-2): ";
						cin >> checkingSelection;
						cout << endl;

						while (checkingSelection != '2') {
							if (checkingSelection == '1') {
								double overdraft;

								cout << "Enter new overdraft limit: ";
								cin >> overdraft;

								if (overdraft > 0) {
									checkingArr[checkingIndex].setOverDraftLimit(overdraft);
									cout << "Overdraft limit updated." << endl;

								}

								else
									cout << "Invalid input." << endl << endl;
							}

							else
								cout << "Invalid input." << endl << endl;

							cout << "MODIFY CHECKING ACCOUNT" << endl;
							cout << "1. Overdraft Limit" << endl;
							cout << "2. Go Back" << endl;
							cout << "What would you like to modify? (1-2): ";
							cin >> checkingSelection;
							cout << endl;
						}
					}

					else if (accountChoice == '3') {
						cout << "SAVING ACCOUNT INFORMATION" << endl;
						// insert info
					}

					else {
						cout << "Enter a valid value." << endl;
					}

					cout << "MODIFY ACCOUNT" << endl;
					cout << "1. Customer Information" << endl;
					cout << "2. Checking Accounts" << endl;
					cout << "3. Saving Accounts" << endl;
					cout << "4. Go Back" << endl;
					cout << "Select a menu option (1-4): ";
					cin >> accountChoice;
					cout << endl;
				}
			}

			else if (choice == '2') {
				int accountID, accountNumber = 1;

				for (int i = 0; i < checkingIndex; i++) {
					if (checkingArr[i].getCustomer()->getPhone() == customerList[customerIndex].getPhone()) {  //if?
						cout << endl << "Account " << accountNumber << endl; // fix this
						customerList[i].printInfo();
						cout << "ID: " << checkingArr[i].getid() << endl;
						cout << "Balance: $";
						cout << fixed << showpoint << setprecision(2) << checkingArr[i].getBalance() << endl;
						cout << "Overdraft limit: $";
						cout << fixed << showpoint << setprecision(2) << checkingArr[i].getOverDraftLimit() << endl;
						cout << "------------------------------------------" << endl << endl;
						accountNumber++;
					}
				}

				cout << "Enter the ID number of the account you wish to delete (enter 0 to quit): " << endl;
				cin >> accountID;

				while (accountID != 0) { // FIXME
					for (int i = 0; i < customerIndex; i++) {
						if (checkingArr[i].getid() == accountID) {
							char confirm;
							cout << "Are you sure you want to delete this account? (Y/N): ";
							cin >> confirm;

							if (confirm == 'y' || confirm == 'Y') {
								checkingArr[i].setAll(0, 0, nullptr, 0);
							}

							else if (confirm == 'n' || confirm == 'N') {
								cout << "Cancelling deletion." << endl;
							}

							else {
								cout << "Invalid option." << endl;
								cout << endl;
							}
						}
					}

					cout << "Enter the ID number of the account you wish to delete (enter 0 to quit): " << endl;
					cin >> accountID;
					cout << endl;
				}
			}

			else
				cout << "Invalid option. Please input a valid menu option." << endl << endl;

			cout << "OPTIONS" << endl;
			cout << "1. Modify an account" << endl;
			cout << "2. Delete an account" << endl;
			cout << "3. Back to main menu" << endl;
			cout << "Select a menu option: ";
			cin >> choice;
			cout << endl;
		}
	}
	cout << endl;
}

void transferSavingAccount(const int SIZE, Customer customerList[], int& customerIndex, SavingAccount savingArr[], int& savingIndex)
{ // transfer from one saving account to another 

	if (customerIndex < 1)
	{
		cout << "No account has been made." << endl << endl;
	}
	else
	{
		double transferAmount;
		char accountOpt; //Chooses the account you want to transfer to
		int id;
		bool foundIDfrom = false, foundIDTo = false;
		int transferFromIndex = -1, transferToIndex = -1; //Need these to validate if IDs exist

		cout << "Enter ID of the saving account you want to transfer from: ";
		cin >> id;

		while (cin.fail()) //Validates if ID uses letters	
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Need to use numbers. Enter ID: ";
			cin >> id;
		}

		for (int i = 0; i < savingIndex; i++)
		{
			if (id == savingArr[i].getid()) //Makes sure ID exists in the system
			{
				foundIDfrom = true;
				transferFromIndex = i; //Saves position of transfer from account
				break;
			}
		}

		if (foundIDfrom == true)
		{
			cout << "Enter ID of the saving account you want to transfer to: ";
			cin >> id;
			while (cin.fail()) //Validates if ID uses letters	
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Need to use numbers. Enter ID: ";
				cin >> id;
			}

			for (int i = 0; i < savingIndex; i++)
			{
				if (id == savingArr[i].getid()) //Makes sure ID exists in the system
				{
					foundIDTo = true;
					transferToIndex = i; //Saves position of transfer from account
					break;
				}
			}

			if (foundIDTo == true)
			{
				cout << "Enter an amount to transfer to saving account: ";
				cin >> transferAmount;
				while (cin.fail()) //Validates if transferAmount uses letters	
				{
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Need to use numbers. Enter an amount: ";
					cin >> transferAmount;
				}
				if (transferAmount <= 0)
				{
					cout << "Not enough money to transfer. Try again!" << endl;
				}
				else
				{
					savingArr[transferFromIndex].transfer(transferAmount, savingArr[transferToIndex]); //Moves money from first account and into the second
				}
			}
			else
			{
				cout << "ID does not exist" << endl; //Shows up if second account doesn't exist
			}
		}
		else
		{
			cout << "ID does not exist" << endl; //Shows up if first account doesn't exist
		}

		cout << endl;
	}
}

void withdraw(const int SIZE, Customer customerList[], int& customerIndex, CheckingAccount checkingArr[], int& checkingIndex) { // withdraw 
	// display accounts

	cout << endl;
}

void depositToChecking(CheckingAccount destinationAccount, double amount) { 
	if (amount > 0) {
		destinationAccount.depositMoney(amount);

	}

	else
		cout << "Invalid input. Voiding deposit." << endl;

	cout << endl;
}

void depositToSavings(SavingAccount destinationAccount, double amount) {
	// no addition yet.

	cout << endl;
}
