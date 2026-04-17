#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;

// Constructors
Customer::Customer()
{
	fname = "";
	lname = "";
	address = "";
	phone = "";
	email = "";
}

Customer::Customer(string _fname, string _lname, string _address, string _phone, string _email)
{
	setFname(_fname);
	setLname(_lname);
	setAddress(_address);
	setPhone(_phone);
	setEmail(_email);
}


// Setters
void Customer::setFname(string _fname)
{
	fname = _fname;
}

void Customer::setLname(string _lname)
{
	lname = _lname;
}

void Customer::setAddress(string _address)
{
	address = _address;
}

void Customer::setPhone(string _phone)
{
	phone = _phone;
}

void Customer::setEmail(string _email)
{
	email = _email;
}

void Customer::setAll(string _fname, string _lname, string _address, string _phone, string _email)
{
	setFname(_fname);
	setLname(_lname);
	setAddress(_address);
	setPhone(_phone);
	setEmail(_email);
}


// Getters
string Customer::getFname() const {
	return fname;
}

string Customer::getLname() const
{
	return lname;
}

string Customer::getAddress() const
{
	return address;
}

string Customer::getPhone() const
{
	return phone;
}

string Customer::getEmail() const
{
	return email;
}

void Customer::printInfo()
{
	cout << "First name: " << fname << endl;
	cout << "Last name: " << lname << endl;
	cout << "Address: " << address << endl;
	cout << "Phone: " << phone << endl;
	cout << "Email: " << email << endl;
}

// Completed
