// Chapter 10 Challenge 6 Vowels and Consonants.cpp
// Adam Burford#2128028
// COP2222#5089 Advanced C++ Programming for Business
// Chapter 10 - Challenge 6: Vowels and Consonants

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const vector<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

int countVowels(const char * s)
{
	int total = 0;

	for (int i = 0; s[i] != '\0'; i++)
		if (any_of(begin(vowels), end(vowels), [&](char d) {return s[i] == d; }))
			total++;

	return total;
}

int countConsonents(const char * s)
{
	int total = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122)) && none_of(begin(vowels), end(vowels), [&](char d) {return s[i] == d; }))
			total++;
	}

	return total;
}

int main()
{
	string s;

	cout << "Enter a string to test: ";
	cin >> s;

	string choice;
	do
	{
		cout << endl;
		cout << "Menu:" << endl;
		cout << "A) Count the number of vowels in the string: " << s << endl;
		cout << "B) Count the number of consonants in the string: " << s << endl;
		cout << "C) Count both the vowels and consonants in the string: " << s << endl;
		cout << "D) Enter another string." << endl;
		cout << "E) Exit the program." << endl;
		cin >> choice;

		if (choice == "a" || choice == "A")
			cout << "The string contains: " << countVowels(s.c_str()) << " vowel(s)." << endl;
		else if (choice == "b" || choice == "B")
			cout << "The string contains: " << countConsonents(s.c_str()) << " consonent(s)." << endl;
		else if (choice == "c" || choice == "C")
			cout << "The string contains: " << countVowels(s.c_str()) << " vowel(s) and " << countConsonents(s.c_str()) << " consonent(s)." << endl;
		else if (choice == "d" || choice == "D")
		{
			cout << "Enter a new string : ";
			cin >> s;
		}
		else if (choice == "e" || choice == "E")
			continue;
		else
			cout << "Invalid selection" << endl;
		cout << endl;
	} while (choice != "E" && choice != "e");
    return 0;
}

