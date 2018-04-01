// Adam Burford Chapter 15 Problem 3.cpp : Defines the entry point for the console application.
//

/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 15 Problems 3
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

class TeamLeader : public ProductionWorker
{
private:
	int monthlyBonus;
	int yearlyTraining;

public:
	TeamLeader(string name, int id, string hireDate, int shift, double hourlyRate, int monthlyBonus, int yearlyTraining) : ProductionWorker(name, id, hireDate, shift, hourlyRate)
	{
		this->monthlyBonus = monthlyBonus;
		this->yearlyTraining = yearlyTraining;
	}

	int getMontlyBonus() { return monthlyBonus; }
	void setMontlyBonus(int i) { monthlyBonus = i; }

	int getYearlyTraining() { return yearlyTraining; }
	void setYearlyTraining(int i) { yearlyTraining = i; }
};

int main()
{
	string name;
	int id;
	string hireDate;
	int shift;
	double hourlyRate;
	int montlyBonus;
	int yearlyTraining;

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

	cout << "Montly Bonus: ";
	cin >> montlyBonus;

	cout << "Yearly Training Hours: ";
	cin >> yearlyTraining;


	TeamLeader employee(name, id, hireDate, shift, hourlyRate, montlyBonus, yearlyTraining);

	cout << endl << "Employee Info: " << endl << endl;
	cout << "Employee name: " << employee.getName() << endl;
	cout << "Employee id: " << employee.getId() << endl;
	cout << "Hire Date: " << employee.getHireDate() << endl;;
	cout << "Shift: " << employee.getShift() << endl;
	cout << "Hourly rate: " << employee.getHourlyRate() << endl;
	cout << "Montly bonus: " << employee.getMontlyBonus() << endl;
	cout << "Yearly Training Hours: " << employee.getYearlyTraining() << endl;


	return 0;
}
