#include "CheckingAccount.h"
#include "SavingAccount.h"
#include "Customer.h"
#include <iostream>
#include <iomanip>
// using namespace std;

// PROTOTYPES

// Menu options
void createChecking(const int SIZE, Customer customerList[], int& customerIndex, CheckingAccount checkingArr[], int& checkingIndex);
void createSaving(const int SIZE, Customer customerList[], int& customerIndex, SavingAccount savingArr[], int& savingIndex);
void viewAccount(const int SIZE, Customer customerList[], int customerIndex, CheckingAccount checkingArr[], int checkingIndex, SavingAccount savingArr[], int savingIndex);
void modifyDeleteAccount(const int SIZE, Customer customerList[], int& customerIndex, CheckingAccount checkingArr[], int& checkingIndex, SavingAccount savingArr[], int& savingIndex);
void transferSavingAccount(const int SIZE, Customer customerList[], int& customerIndex, SavingAccount savingArr[], int& savingIndex);

// Monetary-Based Prototypes
void withdraw(const int SIZE, Customer customerList[], int& customerIndex, CheckingAccount checkingArr[], int& checkingIndex);
void deposit(CheckingAccount checkingArr[], int checkingIndex, SavingAccount savingArr[], int savingIndex);

// Menu
int displayMenu() { //Is value returning so we can return opt
	int opt = 0;
	cout << "||============== MAIN MENU ==============||" << endl;
	cout << "||      1. Create Checking Account       ||" << endl;
	cout << "||      2. Create Saving Account         ||" << endl;
	cout << "||      3. View Account Information      ||" << endl;
	cout << "||      4. Modify Your Account           ||" << endl;
	cout << "||      5. Internal Transfer             ||" << endl;
	cout << "||      6. Withdraw Money                ||" << endl;
	cout << "||      7. Deposit Money                 ||" << endl;
	cout << "||      8. Exit                          ||" << endl;
	cout << "||=======================================||" << endl;

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

	cout << endl;
	return opt;
}

int main()
{
	const int SIZE = 20;

	Customer* customerList = new Customer[SIZE];
	int customerIndex = -1;

	CheckingAccount* checkingArr = new CheckingAccount[SIZE];
	int checkingIndex = -1;

	SavingAccount* savingArr = new SavingAccount[SIZE];
	int savingIndex = -1;

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
			viewAccount(SIZE, customerList, customerIndex, checkingArr, checkingIndex, savingArr, savingIndex);
			break;

		case 4: // Modifying/deleting
			modifyDeleteAccount(SIZE, customerList, customerIndex, checkingArr, checkingIndex, savingArr, savingIndex);
			break;

		case 5: // Transferring  accounts (internal)
			transferSavingAccount(SIZE, customerList, customerIndex, savingArr, savingIndex);
			break;

		case 6: // Withdraw Money
			withdraw(SIZE, customerList, customerIndex, checkingArr, checkingIndex);
			break;

		case 7: // Deposit Money
			deposit(checkingArr, checkingIndex, savingArr, savingIndex);
			break;

		default:
			cout << "Invalid option\n";
			break;
		}
		opt = displayMenu(); //Reprinted from previous while loop
	}

	cout << "You've chosen to exit the program. Farewell!";

	// release the arrays into the wild and free up memory.
	delete[SIZE] customerList;
	delete[SIZE] checkingArr;
	delete[SIZE] savingArr;
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
		cout << "- CREATE A CHECKING ACCOUNT -" << endl;

		customerIndex++;
		checkingIndex++;

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
			cout << "Need to pass a number exactly 10 digits in length. Please try again." << endl;
			cout << "Please re-enter phone number : ";
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


		cout << "Enter balance: ";
		cin >> balance;

		while (balance < 0) {
			cout << "Starting balance cannot start negative! Try again." << endl;

			cout << "Please re-enter balance: ";
			cin >> balance;
		}

		while (cin.fail()) //Validates if balance uses letters
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid balance. Please re-enter balance: ";
			cin >> balance;
		}

		cout << "Enter overdraft limit: ";
		cin >> overdraft;

		while (cin.fail()) //Validates if overdraft uses letters
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid overdraft. Please re-enter overdraft: ";
			cin >> overdraft;
		}
		ID = customerIndex + 1;

		checkingArr[checkingIndex].setAll(ID, balance, &customerList[customerIndex], overdraft);

		cout << "Account ID is " << ID << endl;

		cout << endl;
	}
}

void createSaving(const int SIZE, Customer customerList[], int& customerIndex, SavingAccount savingArr[], int& savingIndex)
{
	string firstName, lastName, address, phone, email;
	bool checking;
	int ID;
	double balance, interestRate;

	cout << "- CREATE A SAVING ACCOUNT -" << endl;

	savingIndex++;

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

	bool isCustomerRegistered = false;
	for (int i = 0; i < customerIndex; i++) {
		if (customerList[customerIndex].getEmail() == email) {
			isCustomerRegistered = true;
		}
	}

	if (isCustomerRegistered = false) {
		customerIndex++;
		customerList[customerIndex].setAll(firstName, lastName, address, phone, email);
	}


	cout << "Enter balance: ";
	cin >> balance;

	while (balance < 0) {
		cout << "Starting balance cannot be negative! Try again." << endl;

		cout << "Please re-enter balance: ";
		cin >> balance;
	}

	while (cin.fail()) //Validates if balance uses letters
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid balance. Please re-enter balance: ";
		cin >> balance;
	}

	cout << "Enter interest rate: ";
	cin >> interestRate;

	while (cin.fail()) //Validates if interest rate uses letters
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid interest rate. Please re-enter interest rate: ";
		cin >> interestRate;
	}

	ID = savingIndex + 1;
	cout << "ID is " << ID << endl;

	savingArr[savingIndex].setAll(ID, balance, &customerList[customerIndex], interestRate);
	cout << endl;
}

void viewAccount(const int SIZE, Customer customerList[], int customerIndex, CheckingAccount checkingArr[], int checkingIndex, SavingAccount savingArr[],
	int savingIndex) { //Views account information

	if (customerIndex < 0) //Makes it so the user can't view accounts that haven't been added yet
	{
		cout << "No accounts have been made. Please try again." << endl << endl;
	}

	else
	{
		char accountType;
		string email;
		bool isViewing;

		cout << "Enter email: ";
		cin >> email;

		for (int i = 0; i < customerIndex; i++) {
			if (customerList[customerIndex].getEmail() == email) {
				isViewing = true;
			}
		}

		while (isViewing = true) {
			cout << "Do you want to view checking or savings? (Type C or S. Type Q to quit): ";
			cin >> accountType;

			if (accountType == 'C' || accountType == 'c') {
				for (int i = 0; i < checkingIndex; i++)
				{
					if (email == checkingArr[i].getCustomer()->getEmail()) {
						cout << "||============= VIEWING ACCOUNT " << i + 1 << " =============||" << endl;
						customerList[i].printInfo();

						cout << "ID: " << checkingArr[i].getid() << endl;

						cout << "Balance: $";
						cout << fixed << showpoint << setprecision(2) << checkingArr[i].getBalance() << endl;

						cout << "Overdraft limit: $";
						cout << fixed << showpoint << setprecision(2) << checkingArr[i].getOverDraftLimit() << endl;

						cout << "||============================================||" << endl << endl;
						cout << "---------------------------------------------" << endl << endl;
					}
					else
						cout << "There are no emails associated with this email address." << endl;
				}
			}

			else if (accountType == 'S' || accountType == 's') // fix format
			{
				for (int i = 0; i < savingIndex; i++)
				{
					if (email == savingArr[savingIndex].getCustomer()->getEmail()) {
						cout << "||============= VIEWING ACCOUNT " << i + 1 << " =============||" << endl;
						savingArr[i].getCustomer()->printInfo();

						cout << "ID: " << savingArr[i].getid() << endl;

						cout << "Balance: $";
						cout << fixed << showpoint << setprecision(2) << savingArr[i].getBalance() << endl;

						cout << "Interest rate: " << savingArr[i].getInterestRate() << "%" << endl;

						cout << "||============================================||" << endl << endl;
						cout << "---------------------------------------------" << endl << endl;
					}

					else {
						cout << "There are no emails associated with this email address." << endl;
					}
				}
			}

			else if (accountType == 'Q' || accountType == 'q') {
				isViewing = false;
			}

			else
			{
				cout << "Invalid response. Please input a C or S for checking or saving accounts, or input Q to quit." << endl;
			}
		}
	}
}

void modifyDeleteAccount(const int SIZE, Customer customerList[], int& customerIndex, CheckingAccount checkingArr[], int& checkingIndex, SavingAccount savingArr[], int& savingIndex) { // modify/delet
	if (customerIndex < 0 && customerList[customerIndex].getPhone() == "") {
		cout << "No account has been made." << endl;
	}

	else {
		int choice;

		cout << "||========== MODIFY OR DELETE ==========||" << endl;
		cout << "||        1. Modify an Account          ||" << endl;
		cout << "||        2. Delete an Account          ||" << endl;
		cout << "||        3. Back to Main Menu          ||" << endl;
		cout << "||======================================||" << endl;

		cout << "Select a menu option (1-3): ";
		cin >> choice;

		while (choice < 1 || choice > 3) {
			cout << "Invalid. Select a menu option (1-3): ";
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
			}
			cin >> choice;
		}

		cout << endl;

		while (choice != 3) {
			if (choice == 1) { // MODIFICATION
				int accountChoice;

				cout << "||============ MODIFY AN ACCOUNT ==========||" << endl;
				cout << "||         1. Customer Information         ||" << endl;
				cout << "||         2. Checking Accounts            ||" << endl;
				cout << "||         3. Saving Accounts              ||" << endl;
				cout << "||         4. Back to Previous Menu        ||" << endl;
				cout << "||=========================================||" << endl;

				cout << "Select a menu option (1-4): ";
				cin >> accountChoice;

				while (accountChoice < 1 || accountChoice > 4) {
					cout << "Invalid. Select a menu option (1-4): ";
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000, '\n');
					}
					cin >> accountChoice;
				}

				cout << endl;

				while (accountChoice != 4) {
					if (accountChoice == 1) {
						int modifyCustomerChoice;

						cout << "||======== CURRENT CUSTOMER DETAILS ======||" << endl;
						customerList[customerIndex].printInfo();
						cout << endl;
						cout << "||========================================||" << endl << endl;
						
						cout << "||============= MODIFY CUSTOMER ==========||" << endl;
						cout << "||          1. Customer Name              ||" << endl;
						cout << "||          2. Home Address               ||" << endl;
						cout << "||          3. Phone Number               ||" << endl;
						cout << "||          4. Email Address              ||" << endl;
						cout << "||          5. Back to Previous Menu      ||" << endl;
						cout << "||========================================||" << endl;

						cout << "What would you like to modify? (1-5): ";
						cin >> modifyCustomerChoice;

						while (modifyCustomerChoice < 1 || modifyCustomerChoice> 5) {
							cout << "Invalid. Select a menu option (1-5): ";
							if (cin.fail()) {
								cin.clear();
								cin.ignore(1000, '\n');
							}
							cin >> modifyCustomerChoice;
						}

						cout << endl;

						while (modifyCustomerChoice != 5) {

							if (modifyCustomerChoice == 1) {
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

							else if (modifyCustomerChoice == 2) {
								string homeAddress;

								cout << "Enter home address: ";
								cin.ignore();
								getline(cin, homeAddress);

								customerList[customerIndex].setAddress(homeAddress);

								cout << "Home address updated." << endl;
								cout << endl;
							}

							else if (modifyCustomerChoice == 3) {
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

							else if (modifyCustomerChoice == 4) {
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

							cout << "||======== CURRENT CUSTOMER DETAILS ======||" << endl;
							customerList[customerIndex].printInfo();
							cout << endl;
							cout << "||========================================||" << endl << endl;

							cout << "||============= MODIFY CUSTOMER ==========||" << endl;
							cout << "||          1. Customer Name              ||" << endl;
							cout << "||          2. Home Address               ||" << endl;
							cout << "||          3. Phone Number               ||" << endl;
							cout << "||          4. Email Address              ||" << endl;
							cout << "||          5. Back to Previous Menu      ||" << endl;
							cout << "||========================================||" << endl;

							cout << "What would you like to modify? (1-5): ";
							cin >> modifyCustomerChoice;

							while (modifyCustomerChoice < 1 || modifyCustomerChoice > 5) {
								cout << "Invalid. What would you like to modify? (1-5): ";
								if (cin.fail()) {
									cin.clear();
									cin.ignore(1000, '\n');
								}
								cin >> modifyCustomerChoice;
							}

							cout << endl;
						}
					}

					else if (accountChoice == 2) { // Fix this to include multiple checking accounts.
						cout << "||======== CHECKING ACCOUNT INFORMATION ======||" << endl;

						int counter = 0;
						for (int i = 0; i <= checkingIndex; i++) {
							if (checkingArr[i].getCustomer()->getEmail() == customerList[customerIndex].getEmail()) {
								counter++;
								cout << "||======== CURRENT CHECKING ACCOUNT " << counter << "=========|| " << endl;
								checkingArr[i].printInfo();

								cout << "ID: " << checkingArr[i].getid() << endl;

								cout << "Balance: $";
								cout << fixed << showpoint << setprecision(2) << checkingArr[i].getBalance() << endl;

								cout << "Overdraft limit: $";
								cout << fixed << showpoint << setprecision(2) << checkingArr[i].getOverDraftLimit() << endl;
								cout << "||========================================||" << endl << endl;
								cout << "--------------------------------------------" << endl << endl;
							}
						}
						cout << endl;

						int checkingSelection;

						cout << "||======== MODIFY CHECKING ACCOUNT ========||" << endl;
						cout << "||         1. Overdraft Limit              ||" << endl;
						cout << "||         2. Back to Previous Menu        ||" << endl;
						cout << "||=========================================||" << endl;

						cout << "What would you like to modify? (1-2): ";
						cin >> checkingSelection;

						while (checkingSelection < 1 || checkingSelection > 2) {
							cout << "Invalid. What would you like to modify? (1-2): ";
							if (cin.fail()) {
								cin.clear();
								cin.ignore(1000, '\n');
							}
							cin >> checkingSelection;
						}

						cout << endl;

						while (checkingSelection != 2) {
							if (checkingSelection == 1) {
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

							cout << "||======== MODIFY CHECKING ACCOUNT ========||" << endl;
							cout << "||         1. Overdraft Limit              ||" << endl;
							cout << "||         2. Back to Previous Menu        ||" << endl;
							cout << "||=========================================||" << endl;

							cout << "What would you like to modify? (1-2): ";
							cin >> checkingSelection;

							while (checkingSelection < 1 || checkingSelection > 2) {
								cout << "Invalid. What would you like to modify? (1-2): ";
								if (cin.fail()) {
									cin.clear();
									cin.ignore(1000, '\n');
								}
								cin >> checkingSelection;
							}

							cout << endl;
						}
					}

					else if (accountChoice == 3) {
						cout << "||========= SAVING ACCOUNT INFORMATION =======||" << endl;
						
						int counter = 0;
						for (int i = 0; i <= savingIndex; i++) {
							if (savingArr[i].getCustomer()->getEmail() == customerList[customerIndex].getEmail()) {
								counter++;
								cout << "||========= CURRENT SAVING ACCOUNT " << counter << " =========|| " << endl;
								savingArr[i].printInfo();

								cout << "ID: " << savingArr[i].getid() << endl;

								cout << "Balance: $";
								cout << fixed << showpoint << setprecision(2) << savingArr[i].getBalance() << endl;


								cout << "Interest Rate: ";
								cout << fixed << showpoint << setprecision(2) << savingArr[i].getInterestRate() << "%" << endl;
								cout << "||========================================||" << endl << endl;
								cout << "--------------------------------------------" << endl << endl;
							}
						}
						cout << endl;

						int checkingSelection;

						cout << "||======== MODIFY CHECKING ACCOUNT ========||" << endl;
						cout << "||         1. Overdraft Limit              ||" << endl;
						cout << "||         2. Back to Previous Menu        ||" << endl;
						cout << "||=========================================||" << endl;

						cout << "What would you like to modify? (1-2): ";
						cin >> checkingSelection;

						while (checkingSelection < 1 || checkingSelection > 2) {
							cout << "Invalid. What would you like to modify? (1-2): ";
							if (cin.fail()) {
								cin.clear();
								cin.ignore(1000, '\n');
							}
							cin >> checkingSelection;
						}

						cout << endl;

						while (checkingSelection != 2) {
							if (checkingSelection == 1) {
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

							cout << "||======== MODIFY CHECKING ACCOUNT ========||" << endl;
							cout << "||         1. Overdraft Limit              ||" << endl;
							cout << "||         2. Back to Previous Menu        ||" << endl;
							cout << "||=========================================||" << endl;

							cout << "What would you like to modify? (1-2): ";
							cin >> checkingSelection;

							while (checkingSelection < 1 || checkingSelection > 2) {
								cout << "Invalid. What would you like to modify? (1-2): ";
								if (cin.fail()) {
									cin.clear();
									cin.ignore(1000, '\n');
								}
								cin >> checkingSelection;
							}

							cout << endl;
						}

						cout << endl;
					}

					else {
						cout << "Enter a valid value." << endl;
					}

					cout << "||============ MODIFY AN ACCOUNT ==========||" << endl;
					cout << "||         1. Customer Information         ||" << endl;
					cout << "||         2. Checking Accounts            ||" << endl;
					cout << "||         3. Saving Accounts              ||" << endl;
					cout << "||         4. Back to Previous Menu        ||" << endl;
					cout << "||=========================================||" << endl;

					cout << "Select a menu option (1-4): ";
					cin >> accountChoice;

					while (accountChoice < 1 || accountChoice > 4) {
						cout << "Invalid. Select a menu option (1-4): ";
						if (cin.fail()) {
							cin.clear();
							cin.ignore(1000, '\n');
						}
						cin >> accountChoice;
					}

					cout << endl;
				}
			}

			else if (choice == 2) {
				int accountID, accountNumber = 1;

				for (int i = 0; i < checkingIndex; i++) {
					if (checkingArr[i].getCustomer()->getEmail() == customerList[customerIndex].getEmail()) {
						cout << endl << "- Account " << accountNumber << " -" << endl;
						cout << "||================ ACCOUNT " << accountNumber << " ==================|| " << endl << endl;

						customerList[i].printInfo();

						cout << "ID: " << checkingArr[i].getid() << endl;

						cout << "Balance: $";
						cout << fixed << showpoint << setprecision(2) << checkingArr[i].getBalance() << endl;

						cout << "Overdraft limit: $";
						cout << fixed << showpoint << setprecision(2) << checkingArr[i].getOverDraftLimit() << endl;

						cout << "||=========================================||" << endl << endl;
						cout << "---------------------------------------------" << endl << endl;
						accountNumber++;
					}
				}

				cout << "Enter the ID number of the account you wish to delete (enter 0 to quit): " << endl;
				cin >> accountID;

				while (accountID < 0 || accountID > customerIndex) {
					cout << "Invalid. Enter the ID number of the account you wish to delete (enter 0 to quit): ";
					if (cin.fail()) {
						cin.clear();
						cin.ignore(1000, '\n');
					}
					cin >> accountID;
				}

				while (accountID != 0) { // FIXME
					for (int i = 0; i < customerIndex; i++) {
						if (checkingArr[i].getid() == accountID) {
							char confirm;
							cout << "Are you sure you want to delete this account? (Y/N): ";
							cin >> confirm;

							if (confirm == 'y' || confirm == 'Y') {
								delete[i] checkingArr;
								break;
							}

							else if (confirm == 'n' || confirm == 'N') {
								cout << "Cancelling deletion." << endl;
								break;
							}

							else {
								cout << "Invalid option." << endl;
								cout << endl;
							}
						}
					}

					char deleteAccount, confirm;
					cout << "Do you wish to delete a saving account or a checking account? (type S or C, Q to quit): ";
					cin >> deleteAccount;

					if (deleteAccount == 'c' || deleteAccount == 'C') {

						cout << "Enter the ID number of the checking account you wish to delete (enter 0 to quit): " << endl;
						cin >> accountID;

						while (accountID < 0 || accountID > checkingIndex) {
							cout << "Invalid. Enter the ID number of the account you wish to delete (enter 0 to quit): ";
							if (cin.fail()) {
								cin.clear();
								cin.ignore(1000, '\n');
							}
							cin >> accountID;
						}

						for (int i = 0; i < checkingIndex; i++) {
							if (accountID == checkingArr[i].getid()) {
								cout << "Do you wish to delete this account? (Y/N): ";
								cin >> confirm;

								if (confirm == 'y' || confirm == 'Y') {
									delete[] &checkingArr[i];
									cout << "Account deleted successfully." << endl;
									break;
								}

								else if (confirm == 'n' || confirm == 'N') {
									cout << "Cancelling deletion." << endl;
									break;
								}

								else {
									cout << "Invalid response, cancelling deletion." << endl;
									break;
								}
							}
						}
					}
					
					else if (deleteAccount == 's' || deleteAccount == 'S') {

						cout << "Enter the ID number of the saving account you wish to delete (enter 0 to quit): " << endl;
						cin >> accountID;

						while (accountID < 0 || accountID > savingIndex) {
							cout << "Invalid. Enter the ID number of the account you wish to delete (enter 0 to quit): ";
							if (cin.fail()) {
								cin.clear();
								cin.ignore(1000, '\n');
							}
							cin >> accountID;
						}

						for (int i = 0; i < savingIndex; i++) {
							if (accountID == savingArr[savingIndex].getid()) {
								cout << "Do you wish to delete this account? (Y/N): ";
								cin >> confirm;

								if (confirm == 'y' || confirm == 'Y') {
									delete[] &savingArr[i];
									cout << "Account deleted successfully." << endl;
									break;
								}

								else if (confirm == 'n' || confirm == 'N') {
									cout << "Cancelling deletion." << endl;
									break;
								}

								else {
									cout << "Invalid response, cancelling deletion." << endl;
									break;
								}
							}
						}
					}
					cout << endl;
				}
			}

			else
				cout << "Invalid option. Please input a valid menu option." << endl << endl;

			
			cout << "||========== MODIFY OR DELETE ==========||" << endl;
			cout << "||        1. Modify an Account          ||" << endl;
			cout << "||        2. Delete an Account          ||" << endl;
			cout << "||        3. Back to Main Menu          ||" << endl;
			cout << "||======================================||" << endl;
			
			cout << "Select a menu option (1-3): ";
			cin >> choice;

			while (choice < 1 || choice > 3) {
				cout << "Invalid. Select a menu option (1-3): ";
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
				}
				cin >> choice;
			}

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

	int checkingNumber = 1;
	int withdrawChoice;
	double withdraw_amount;
	bool isWithdrawing = true;
	string email;

	if (checkingIndex < 1)
		cout << "No account has been made." << endl;

	else {
		for (int i = 0; i < checkingIndex; i++)
		{
			cout << "||============= VIEWING ACCOUNT " << checkingNumber << " =============||" << endl;
			customerList[i].printInfo();

			cout << "ID: " << checkingArr[i].getid() << endl;

			cout << "Balance: $";
			cout << fixed << showpoint << setprecision(2) << checkingArr[i].getBalance() << endl;

			cout << "Overdraft limit: $";
			cout << fixed << showpoint << setprecision(2) << checkingArr[i].getOverDraftLimit() << endl;

			cout << "||=========================================||" << endl << endl;
			cout << "---------------------------------------------" << endl << endl;
			checkingNumber++;
		}

		if (checkingNumber > 1) {

			cout << "Enter the ID of the account you wish to withdraw from (type 0 to quit): ";
			cin >> withdrawChoice;

			cout << endl << "------------------------------------------" << endl;

			while (withdrawChoice < 0 || withdrawChoice > sizeof(checkingArr)) {
				cout << "Invalid! Please re-enter a valid ID (or type 0 to quit): ";

				if (cin.fail()) {
					cin.clear();
					cin.ignore(1000, '\n');
				}
				cin >> withdrawChoice;
			}

			while (isWithdrawing = true) {
				for (int i = 0; i < checkingIndex; i++) {
					if (withdrawChoice > 0 && withdrawChoice == checkingArr[i].getid()) {
						cout << "Enter the amount you would like to withdraw (type -1 to quit): ";
						cin >> withdraw_amount;

						if (withdraw_amount == -1)
							isWithdrawing = false;

						else if (withdraw_amount <= checkingArr[checkingIndex].getBalance() && withdraw_amount > 0) {
							checkingArr[checkingIndex].withdrawMoney(withdraw_amount);

							cout << "---------------------------------------------" << endl << endl;
							cout << "||================ RECEIPT ================||" << endl << endl;

							cout << "SOURCE ACCOUNT ID: " << checkingArr[i].getid() << endl;

							cout << "AMOUNT WITHDRAWN: $";
							cout << fixed << showpoint << setprecision(2) << withdraw << endl;

							cout << "UPDATED BALANCE: $";
							cout << fixed << showpoint << setprecision(2) << checkingArr[i].getBalance() << endl;

							cout << "CUMULATIVE WITHDRAWALS MADE: " << checkingArr[i].getWithdrawCounter() << endl;

							cout << "||============ END OF RECEIPT =============||" << endl << endl;
							cout << "---------------------------------------------" << endl << endl;
						}

						else
							cout << "Invalid input." << endl;
					}
				}
			}
		}
	}
	
}

void deposit(CheckingAccount checkingArr[], int checkingIndex, SavingAccount savingArr[], int savingIndex) {
	double deposit;
	int checkingNumber = 1, savingNumber = 1;
	char depositChoice;
	bool isDepositing = true;

	cout << "Are you depositing money into a checking or a saving account? (type C, S, or Q (quit)): ";
	cin >> depositChoice;

	cout << endl << "------------------------------------------" << endl;
	while (isDepositing == true) {
		if (checkingIndex < 1) {
			cout << "No account has been made." << endl;
			isDepositing = false;
		}
		
		else {
			if (depositChoice == 'c' || depositChoice == 'C') {
				for (int i = 0; i <= sizeof(checkingArr); i++) {
					if (checkingArr[i].getCustomer() != nullptr && checkingArr[i].getid() > 0) {
						cout << "- Checking Account " << checkingNumber << " Information -" << endl;
						checkingArr[i].printInfo();
						cout << "------------------------------------------" << endl << endl;
					}
				}

				int destinationID;
				cout << "Enter the ID of the account you wish to deposit money into: ";
				cin >> destinationID;

				for (int i = 0; i <= sizeof(checkingArr); i++) {
					if (destinationID == checkingArr[i].getid()) {
						cout << "Enter the amount to deposit into account " << destinationID << " :";
						cin >> deposit;

						if (deposit > 0) {
							checkingArr[i].depositMoney(deposit);
							cout << "---------------------------------------------" << endl;
							cout << "||================ RECEIPT ================||" << endl << endl;

							cout << "DESTINATION ACCOUNT ID: " << checkingArr[i].getid() << endl;

							cout << "DEPOSITED AMOUNT: $";
							cout << fixed << showpoint << setprecision(2) << deposit << endl;

							cout << "UPDATED BALANCE: $";
							cout << fixed << showpoint << setprecision(2) << checkingArr[i].getBalance() << endl;

							cout << "CUMULATIVE DEPOSITS MADE: " << checkingArr[i].getDepositCounter() << endl;

							cout << "||============ END OF RECEIPT =============||" << endl << endl;
							cout << "---------------------------------------------" << endl << endl;
						}

						else {
							cout << "Deposit is invalid." << endl;
						}
					}
				}
			}


			else if (depositChoice == 's' || depositChoice == 'S') {
				for (int i = 0; i <= sizeof(savingArr); i++) {
					if (savingArr[i].getCustomer() != nullptr && savingArr[i].getid() > 0) {
						cout << "- Saving Account " << savingNumber << " Information -" << endl;
						savingArr[i].printInfo();
						cout << "------------------------------------------" << endl << endl;
					}
				}

				int destinationID;
				cout << "Enter the ID of the account you wish to deposit money into: ";
				cin >> destinationID;

				for (int i = 0; i <= sizeof(savingArr); i++) {
					if (destinationID == savingArr[i].getid()) {
						cout << "Enter the amount to deposit into account " << destinationID << " :";
						cin >> deposit;

						if (deposit > 0) {
							savingArr[i].depositMoney(deposit);
							cout << "---------------------------------------------" << endl;
							cout << "||================ RECEIPT ================||" << endl << endl;

							cout << "DESTINATION ACCOUNT ID: " << savingArr[i].getid() << endl;

							cout << "DEPOSITED AMOUNT: $";
							cout << fixed << showpoint << setprecision(2) << deposit << endl;

							cout << "UPDATED BALANCE: $";
							cout << fixed << showpoint << setprecision(2) << savingArr[i].getBalance() << endl;

							cout << "CUMULATIVE DEPOSITS MADE: " << savingArr[i].getDepositCounter() << endl;

							cout << "||============ END OF RECEIPT =============||" << endl << endl;
							cout << "---------------------------------------------" << endl << endl;
						}

						else {
							cout << "Deposit is invalid." << endl;
						}
					}
				}
			}

			else if (depositChoice == 'q' || depositChoice == 'Q') {
				cout << "Canceling deposit." << endl;
				isDepositing = false;
			}

		else
			cout << "The only options are C (checking), S (saving), or Q (quit)." << endl;
		}

		cout << "Are you depositing money into a checking or a saving account? (type C, S, or Q (quit)): ";
		cin >> depositChoice;
	}

	cout << endl;
}
