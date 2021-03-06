// Adam Burford Chapter 14 Problem 4.cpp : Defines the entry point for the console application.
//

/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 14 Problem 4-6
*/

#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class NumDays 
{
	private:
		int hours;
		double days;
	public:
		NumDays()
		{
			hours = 0;
			days = 0;
		}

		NumDays(int hours)
		{
			this->hours = hours;
			this->days = this->hours / 8.0;
		}

		int getHours() { return this->hours; }
		void setHours(int hours) { this->hours = hours; this->days = this->hours / 8.0; }

		double getDays() { return this->days; }
		void setDays(double days) { this->days = days; this->hours = (int)round(this->days * 8.0); }

		NumDays operator + (const NumDays &right)
		{
			return NumDays(this->hours + right.hours);
		}

		NumDays operator - (const NumDays &right)
		{
			return NumDays(this->hours - right.hours);
		}

		NumDays operator ++ ()
		{
			hours++;
			days = hours / 8.0;
			return *this;
		}

		NumDays operator -- ()
		{
			hours--;
			days = hours / 8.0;
			return *this;
		}
};

class TimeOff 
{
	private:
		NumDays maxSickDays;
		NumDays sickTaken;
		NumDays maxVacation;
		NumDays vacTaken;
		NumDays maxUnpaid;
		NumDays unpaidTaken;

		string name;
		int id;

	public:
		TimeOff(string name, int id, NumDays maxSickDays, NumDays sickTaken, NumDays maxVacation, NumDays vacTaken, NumDays maxUnpaid, NumDays unpaidTaken)
		{
			this->name = name;
			this->id = id;
			this->maxSickDays = maxSickDays;
			this->sickTaken = sickTaken;
			if (maxVacation.getHours() > 240)
				this->maxVacation = NumDays(240);
			else
				this->maxVacation = maxVacation;
			this->vacTaken = vacTaken;
			this->maxUnpaid = maxUnpaid;
			this->unpaidTaken = unpaidTaken;
		}

		string getName() { return name; }
		void setName(string name) { this->name = name; }

		int getId() { return id; }
		void setId(int id) { this->id = id; }

		NumDays getMaxSickDays() { return maxSickDays; }
		NumDays getSickTaken() { return sickTaken; }
		NumDays getMaxVacation() { return maxVacation; }
		NumDays getVacTaken() { return vacTaken; }
		NumDays getMaxUnpaid() { return maxUnpaid; }
		NumDays getUnpaidTaken() { return unpaidTaken; }

		void setMaxSickDays(NumDays n) { this->maxSickDays = n; }
		void setSickTaken(NumDays n) { this->sickTaken = n; }
		void setMaxVaction(NumDays n) { if (n.getHours() > 240) this->maxVacation = NumDays(240);else this->maxVacation = n; }
		void setVacTaken(NumDays n) { this->vacTaken = n; }
		void setMaxUnpaid(NumDays n) { this->maxUnpaid = n; }
		void setUnpaidTaken(NumDays n) { this->unpaidTaken = n; }

};

int main()
{
	string name;
	int id;
	int monthsWorked;

	cout << "Enter employee name: ";
	getline(cin, name);

	cout << "Enter employee id: ";
	cin >> id;

	cout << "Enter the number of months employed: ";
	cin >> monthsWorked;


	TimeOff employee(name, id, NumDays(monthsWorked * 8), NumDays(0), NumDays(monthsWorked * 12), NumDays(0), NumDays(0), NumDays(0));

	cout << "Employee Name: " << employee.getName() << endl;
	cout << "Employee Id: " << employee.getId() << endl;
	cout << "Employee Max Sick Days: " << employee.getMaxSickDays().getDays() << endl;
	cout << "Employee Max Vacation Days: " << employee.getMaxVacation().getDays() << endl;

    return 0;
}

