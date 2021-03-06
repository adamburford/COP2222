// Adam Burford #2128028
// Oct 16, 2017
// COP2222#5089
// Chapter 9 Programming Challenge 11 - Array Expander

#include <iostream>
using namespace std;

int * arrayExpander(int * a, int s)
{
	int * b = new int[s * 2];

	for (int i = 0; i < s; i++)
		*(b + i) = *(a + s - i - 1);

	for (int i = s; i < s * 2; i++)
		*(b + i) = 0;

	return b;
}

int main()
{
	int test[] = { 1, 2, 3, 4, 5 };

	for (auto i : test)
		cout << i;
	cout << endl;

	int * expanded = arrayExpander(test, 5);

	for (int i = 0; i < 10; i++)
		cout << *(expanded + i);
	cout << endl;

    return 0;
}

