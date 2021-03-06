// Adam Burford Chapter 13 Problem 2.cpp : Defines the entry point for the console application.
//
/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 13 Problem 2
*/

#include <iostream>
#include <string>
using namespace std;

class Employee
{
	private:
		string name;
		int idNumber;
		string department;
		string position;


	public:
		Employee(string name, int idNumber, string department, string position)
		{
			this->name = name;
			this->idNumber = idNumber;
			this->department = department;
			this->position = position;
		}

		Employee(string name, int idNumber)
		{
			this->name = name;
			this->idNumber = idNumber;
			this->department = "";
			this->position = "";
		}

		Employee()
		{
			this->name = "";
			this->idNumber = 0;
			this->department = "";
			this->position = "";
		}

		string getName() { return name; }
		int getIdNumber() { return idNumber; }
		string getDepartment() { return department; }
		string getPosition() { return position; }

		void setName(string name) { this->name = name; }
		void setIdNumber(int idNumber) { this->idNumber = idNumber; }
		void setDepartment(string department) { this->department = department; }
		void setPosition(string position) { this->position = position; }
};

int main()
{
	Employee employee1 = Employee("Susan Meyers", 47899, "Accounting", "Vice President");
	Employee employee2 = Employee("Mark Jones", 39119, "IT", "Programmer");
	Employee employee3 = Employee("Joy Rogers", 81774, "Manufacturing", "Engineer");

	cout << "Employee 1: " << endl;
	cout << "Name: " << employee1.getName() << endl;
	cout << "ID Number: " << employee1.getIdNumber() << endl;
	cout << "Department: " << employee1.getDepartment() << endl;
	cout << "Position: " << employee1.getPosition() << endl;
	cout << endl;

	cout << "Employee 2: " << endl;
	cout << "Name: " << employee2.getName() << endl;
	cout << "ID Number: " << employee2.getIdNumber() << endl;
	cout << "Department: " << employee2.getDepartment() << endl;
	cout << "Position: " << employee2.getPosition() << endl;
	cout << endl;

	cout << "Employee 3: " << endl;
	cout << "Name: " << employee3.getName() << endl;
	cout << "ID Number: " << employee3.getIdNumber() << endl;
	cout << "Department: " << employee3.getDepartment() << endl;
	cout << "Position: " << employee3.getPosition() << endl;
	cout << endl;

    return 0;
}

