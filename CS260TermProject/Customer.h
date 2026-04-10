#pragma once
#ifndef _CUSTOMER_
#define _CUSTOMER_
#include <string>

//Customer class
class Customer {
	string fname, lname, address;
	int phone;
	string email;
public:
	//Constructors
	Customer();
	Customer(string _fname, string _lname, string _address, int _phone, string _email);

	//Setters
	void setFname(string _fname);
	void setLname(string _fname);
	void setAddress(string _fname);
	void setPhone(int _fname);
	void setEmail(string _fname);

	//Getters
	string getFname() const;
	string getLname() const;
	string getAddress() const;
	int getPhone() const;
	string getEmail() const;

	//SetAll
	void setAll(string _fname, string _lname, string _address, int _phone, string _email);

	//Print
	void printInfo();
};

#endif // !_CUSTOMER_
