#include <iostream>
#include "Customer.h"
#include "Account.h"

using namespace std;

int main()
{
	//Customer customerList[5];

	int opt;
	cout << "Main menu\nOption 1\nOption 2\nOption 3\nOption 4\nOption 5\nExit (6)\n";
	cout << "Enter option (1-6): ";
	cin >> opt;

	while (opt < 1 || opt > 6) //Checks if option is valid
	{
		cout << "Invalid option" << endl << endl;
		cout << "\nMain menu\nOption 1\nOption 2\nOption 3\nOption 4\nOption 5\nExit (6)\n";
		cout << "Enter option (1-6): ";
		cin >> opt;
	}
	while (opt != 6) 
	{
		switch (opt) 
		{
			case 1:
				cout << "Option 1 Chosen\n";
				break;
			case 2: 
				cout << "Option 2 Chosen\n";
				break;
			case 3:
				cout << "Option 3 Chosen\n";
				break;
			case 4:
				cout << "Option 4 Chosen\n";
				break;
			case 5:
				cout << "Option 5 Chosen\n";
				break;
			default: 
				cout << "Invalid option\n";
				break;
		}

		cout << "\nMain menu\nOption 1\nOption 2\nOption 3\nOption 4\nOption 5\nExit (6)\n"; //Makes sure loop isn't infinite
		cout << "Enter option (1-6): ";
		cin >> opt;
	}

	cout << "You've chosen to exit the program. Farewell!";
	return 0;
}