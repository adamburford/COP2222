// Adam Burford Chapter 15 Problem 2.cpp : Defines the entry point for the console application.
//

/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 15 Problems 2
*/

#include <string>
#include <iostream>
using namespace std;

class Employee
{
protected:
	string name;
	int id;
	string hireDate;

public:
	Employee(string name, int id, string hireDate)
	{
		this->name = name;
		this->id = id;
		this->hireDate = hireDate;
	}

	string getName() { return name; }
	int getId() { return id; }
	string getHireDate() { return hireDate; }

	void setName(string s) { name = s; }
	void setId(int i) { id = i; }
	void setHireDate(string s) { hireDate = s; }
};

class ShiftSupervisor : public Employee
{
private:
	int salary;
	int bonus;

public:
	ShiftSupervisor(string name, int id, string hireDate, int salary, int bonus) : Employee(name, id, hireDate)
	{
		this->salary = salary;
		this->bonus = bonus;
	}

	int getSalary() { return salary; }
	void setSalary(int i) { salary = i; }

	int getBonus() { return bonus; }
	void setBonus(int i) { bonus = i; }

};

int main()
{

	string name;
	int id;
	string hireDate;
	int salary;
	int bonus;

	cout << "Enter employee name: ";
	getline(cin, name);

	cout << "Employee id: ";
	cin >> id;

	cout << "Hire Date: ";
	cin >> hireDate;

	cout << "Salary: ";
	cin >> salary;

	cout << "Production Bonus: ";
	cin >> bonus;

	ShiftSupervisor employee(name, id, hireDate, salary, bonus);

	cout << endl << "Employee Info: " << endl << endl;
	cout << "Employee name: " << employee.getName() << endl;
	cout << "Employee id: " << employee.getId() << endl;
	cout << "Hire Date: " << employee.getHireDate() << endl;;
	cout << "Salary: " << employee.getSalary() << endl;
	cout << "Production Bonus: " << employee.getBonus() << endl;
    return 0;
}

