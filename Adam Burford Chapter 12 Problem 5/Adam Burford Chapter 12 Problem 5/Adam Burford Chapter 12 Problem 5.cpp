// Adam Burford Chapter 12 Problem 5.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 12 Problem 5 
*/

int main()
{
	string name;
	cout << "Enter file name: ";
	cin >> name;
	fstream file(name, ios::in);
	if (file)
	{
		string line;
		int lineNum = 1;
		while (!file.eof())
		{
			getline(file, line);
			cout << lineNum << ":" << line << endl;
			if (lineNum % 24 == 0)
				system("pause");
			lineNum++;
		}
	}

	file.close();
    return 0;
}

