// Chapter 11 Problem 8.cpp : Defines the entry point for the console application.
//

/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 11 Problem 8 Customer Accounts
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Delcare structure to represent customer
struct Customer
{
	string name;
	string address;
	string cityStateZip;
	string phoneNumber;
	double accountBalance = 0.0;
	string dateOfLastPayment;
};



// Function to enter customer data
Customer enterCustomer()
{
	Customer c;
	cout << "Name: ";
	cin >> c.name;
	cout << "Address: ";
	cin >> c.address;
	cout << "City, State, Zip: ";
	cin >> c.cityStateZip;
	cout << "Telephone Number: ";
	cin >> c.phoneNumber;
	do
	{
		string input;
		cout << "Account Balance: ";
		cin >> input;
		c.accountBalance = stod(input);
		if (c.accountBalance < 0)
			cout << "Account Balance can not be negitive!" << endl << "Try again" << endl;
	} while (c.accountBalance < 0);

	cout << "Date of last payment: ";
	cin >> c.dateOfLastPayment;

	return c;
}

void addAllCustomers(Customer a[], int size)
{
	cout << endl << "Enter Customer Data: " << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << endl << "Customer " << i + 1 << ": " << endl;
		a[i] = enterCustomer();
	}
}

// Function to update single customer data
void updateCustomerData(Customer a[], int size)
{
	int i;
	do
	{
		cout << "Enter customer number to update: ";
		cin >> i;
		if (i < 1 || i > size)
		{
			cout << "Invalid customer number!" << endl;
			cout << "Enter a number beteen 1 and " << size << endl;
		}
	} while (i < 1 || i > size);
	i -= 1;

	cout << "Choose what to update" << endl;
	cout << "1) Update all" << endl;
	cout << "2) Name: " << endl;
	cout << "3) Address: " << endl;
	cout << "4) City, State, Zip: " << endl;
	cout << "5) Telephone Number: " << endl;
	cout << "6) Account Balance: " << endl;
	cout << "7) Date of Last Payment: " << endl;

	int j;
	cin >> j;

	switch (j)
	{
	case 1:
		a[i] = enterCustomer();
		break;
	case 2:
		cout << "Name: ";
		cin >> a[i].name;
		break;
	case 3:
		cout << "Address: ";
		cin >> a[i].address;
		break;
	case 4:
		cout << "City, State, Zip: ";
		cin >> a[i].cityStateZip;
		break;
	case 5:
		cout << "Telephone Number: ";
		cin >> a[i].phoneNumber;
	case 6:
		do
		{
			string input;
			cout << "Account Balance: ";
			cin >> input;
			a[i].accountBalance = stod(input);
			if (a[i].accountBalance < 0)
				cout << "Account Balance can not be negitive!" << endl << "Try again" << endl;
		} while (a[i].accountBalance < 0);
		break;
	case 7:
		cout << "Date of last payment: ";
		cin >> a[i].dateOfLastPayment;
		break;
	default:
		cout << "Invalid Selection! Try again" << endl;
		break;
	}
}

// Fucntion to diplay all customer information
void displayCustomers(Customer a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Customer " << i + 1 << ": " << endl;
		cout << "Name: " << a[i].name << endl;
		cout << "Address: " << a[i].address << endl;
		cout << "City, State, Zip: " << a[i].cityStateZip << endl;
		cout << "Telephone Number: " << a[i].phoneNumber << endl;
		cout << "Account Balance: " << a[i].accountBalance << endl;
		cout << "Date of Last Payment: " << a[i].dateOfLastPayment << endl << endl;
	}

}

void searchCustomers(Customer a[], int size)
{
	string s;
	cout << "Enter name to search for: ";
	cin >> s;

	cout << "Customers with that name: " << endl << endl;
	for (int i = 0; i < size; i++)
	{
		if (a[i].name.find(s) != string::npos)
		{
			cout << "Customer " << i + 1 << ": " << endl;
			cout << "Name: " << a[i].name << endl;
			cout << "Address: " << a[i].address << endl;
			cout << "City, State, Zip: " << a[i].cityStateZip << endl;
			cout << "Telephone Number: " << a[i].phoneNumber << endl;
			cout << "Account Balance: " << a[i].accountBalance << endl;
			cout << "Date of Last Payment: " << a[i].dateOfLastPayment << endl << endl;
		}
	}
}

int main()
{
	int choice;

	const int size = 10;
	Customer customerArray[size];

	do
	{
		cout << endl << "Customer Accounts Simulator" << endl << endl;
		cout << "1) Enter customer data" << endl;
		cout << "2) Update customer data" << endl;
		cout << "3) Display customer data" << endl;
		cout << "4) Search for customer" << endl;
		cout << "5) Exit" << endl;

		cin >> choice;

		if (choice == 1)
			addAllCustomers(customerArray, size);
		else if (choice == 2)
			updateCustomerData(customerArray, size);
		else if (choice == 3)
			displayCustomers(customerArray, size);
		else if (choice == 4)
			searchCustomers(customerArray, size);
		else if (choice == 5)
		{
			cout << "Exit" << endl;
			return 0;
		}
		else
			cout << "Invalid selection" << endl;
	} while (true);

}

