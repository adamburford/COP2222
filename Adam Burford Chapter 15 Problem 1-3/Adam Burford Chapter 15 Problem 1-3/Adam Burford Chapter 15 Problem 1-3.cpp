// Adam Burford Chapter 15 Problem 1-3.cpp : Defines the entry point for the console application.
//

/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 15 Problems 1-3
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

class ProductionWorker : public Employee
{
	private:
		int shift;
		double hourlyRate;

	public:
		ProductionWorker(string name, int id, string hireDate, int shift, double hourlyRate) : Employee(name, id, hireDate)
		{
			this->shift = shift;
			this->hourlyRate = hourlyRate;
		}

		string getShift() { if (shift == 1) return "Day Shift"; if (shift == 2) return "Night Shift"; return "Invalid Shift"; }
		void setShift(int i) { id = i; }

		double getHourlyRate() { return hourlyRate; }
		void setHourlyRate(double d) { hourlyRate = d; }
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

	ProductionWorker employee(name, id, hireDate, shift, hourlyRate);

	cout << endl << "Employee Info: " << endl << endl;
	cout << "Employee name: " << employee.getName() << endl;
	cout << "Employee id: " << employee.getId() << endl;
	cout << "Hire Date: " << employee.getHireDate() << endl;;
	cout << "Shift: " << employee.getShift() << endl;
	cout << "Hourly rate: " <<employee.getHourlyRate() <<endl;


    return 0;
}

