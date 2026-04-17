#pragma once
#ifndef _CUSTOMER_
#define _CUSTOMER_
#include <string>
using namespace std;

//Customer class
class Customer {
	string fname, lname, address, phone, email;
public:
	//Constructors
	Customer();
	Customer(string _fname, string _lname, string _address, string _phone, string _email);

	//Setters
	void setFname(string _fname);
	void setLname(string _fname);
	void setAddress(string _fname);
	void setPhone(string _fname);
	void setEmail(string _fname);

	//Getters
	string getFname() const;
	string getLname() const;
	string getAddress() const;
	string getPhone() const;
	string getEmail() const;

	//SetAll
	void setAll(string _fname, string _lname, string _address, string _phone, string _email);

	//Print
	void printInfo();
};

#endif // !_CUSTOMER_

// completed
