// Adam Burford Chapter 17 Problem 1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <set>
using namespace std;

/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 17 Problem 1
*/

int main()
{
	string name = "forChap12.txt";
	fstream file(name, ios::in);
	string word;
	set<string> wordList;

	if (file)
	{
		while (file >> word)
		{
			word.erase(remove_if(word.begin(), word.end(), ispunct));
			wordList.insert(word);
		}
	}

	file.close();

	cout << "Words in the file: ";

	for (auto i : wordList)
	{
		cout << i << ", ";
	}
	return 0;
}