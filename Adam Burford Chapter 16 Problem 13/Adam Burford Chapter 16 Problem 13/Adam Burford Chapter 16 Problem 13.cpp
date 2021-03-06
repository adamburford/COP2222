// Adam Burford Chapter 15 Problem 1-3.cpp : Defines the entry point for the console application.
//

/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 16 Problem 13
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
	class InvalidEmployeeNumber
	{
	private:
		int number;
	public:
		InvalidEmployeeNumber(int number)
		{
			this->number = number;
		}
		int getValue() { return number; }
	};
	
	Employee(string name, int id, string hireDate)
	{
		this->name = name;
		if (id < 0 || id > 9999)
			throw InvalidEmployeeNumber(id);
		else
			this->id = id;
		this->hireDate = hireDate;
	}



	string getName() { return name; }
	int getId() { return id; }
	string getHireDate() { return hireDate; }

	void setName(string s) { name = s; }
	void setId(int i) { if (id < 0 || id > 9999) throw InvalidEmployeeNumber(id); else id = i; }
	void setHireDate(string s) { hireDate = s; }
};

class ProductionWorker : public Employee
{
private:
	int shift;
	double hourlyRate;

public:
	ProductionWorker(string name, int id, string hireDate, int shift, double hourlyRate) : Employee(name, id, hireDate)
	{
		if (!(shift == 1 || shift == 2))
			throw InvalidShift(shift);
		else
			this->shift = shift;
		if (hourlyRate < 0)
			throw InvalidPayRate(hourlyRate);
		else
			this->hourlyRate = hourlyRate;
	}

	class InvalidShift
	{
	private:
		int shift;
	public:
		InvalidShift(int i) { shift = i; }
		int getValue() { return shift; }
	};

	class InvalidPayRate
	{
	private:
		double payRate;
	public:
		InvalidPayRate(double d) { payRate = d; }
		double getValue() { return payRate; }
	};

	string getShift() { if (shift == 1) return "Day Shift"; if (shift == 2) return "Night Shift"; return "Invalid Shift"; }
	void setShift(int i) 
	{
		if (!(i == 1 || i == 2))
			throw InvalidShift(i);
		else
			this->shift = i;
	}

	double getHourlyRate() { return hourlyRate; }
	void setHourlyRate(double d) 
	{ 
		if (d < 0)
			throw InvalidPayRate(d);
		else
			hourlyRate = d; 
	}
};

int main()
{
	string name;
	int id;
	string hireDate;
	int shift;
	double hourlyRate;

	cout << "Enter employee name: ";
	getline(cin, name);

	cout << "Employee id: ";
	cin >> id;

	cout << "Hire Date: ";
	cin >> hireDate;

	cout << "Shift: ";
	cin >> shift;

	cout << "Hourly rate: ";
	cin >> hourlyRate;

	try {
		ProductionWorker employee(name, id, hireDate, shift, hourlyRate);
		cout << endl << "Employee Info: " << endl << endl;
		cout << "Employee name: " << employee.getName() << endl;
		cout << "Employee id: " << employee.getId() << endl;
		cout << "Hire Date: " << employee.getHireDate() << endl;;
		cout << "Shift: " << employee.getShift() << endl;
		cout << "Hourly rate: " << employee.getHourlyRate() << endl;
	}
	catch (ProductionWorker::InvalidEmployeeNumber e) {
		cout << "Invalid Employee Number: " << e.getValue() << endl;
	}
	catch (ProductionWorker::InvalidPayRate e) {
		cout << "Invalid Pay Rate: " << e.getValue() <<endl;
	}
	catch (ProductionWorker::InvalidShift e) {
		cout << "Invalid Shift: " << e.getValue() <<endl;
	}

	return 0;
}

