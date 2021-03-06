// Adam Burford Chapter 19 Problem 7 MathStack.cpp : Defines the entry point for the console application.
//

/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 19 Problem 7 MathStack
*/

#include <iostream>
using namespace std;

class IntStack
{
private:
	int *stackArray;
	int stackSize;
	int top;

public:
	IntStack(int size)
	{
		stackArray = new int[size];
		stackSize = size;
		top = -1;
	}

	IntStack(const IntStack &obj)
	{
		if (obj.stackSize > 0)
			stackArray = new int[obj.stackSize];
		else
			stackArray = nullptr;

		stackSize = obj.stackSize;

		for (int i = 0; i < stackSize; i++)
			stackArray[i] = obj.stackArray[i];

		top = obj.top;
	}

	~IntStack() 
	{
		delete[] stackArray;
	}

	void push(int i) 
	{
		if (isFull())
			cout << "The stack is full" << endl;
		else
		{
			top++;
			stackArray[top] = i;
		}
	}

	void pop(int &i) 
	{
		if (isEmpty())
			cout << "The stack is empty" << endl;
		else 
		{
			i = stackArray[top];
			top--;
		}
	}
	bool isFull() const
	{
		if (top == stackSize - 1)
			return true;
		else
			return false;
	}

	bool isEmpty() const
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	void print() 
	{ 
		for (int i = 0; i <= top; i++)
			cout << stackArray[i] << " ";
		cout << endl;
		/*
		cout << "[" << *stackArray; 
		for (int i = 1; i < top; i++)
			cout << ", " << i;
		cout << "]" << endl;
		*/
	}
};

class MathStack : public IntStack
{
public:
	MathStack(int s) : IntStack(s) {}

	void add()
	{
		int num, sum;

		pop(sum);
		pop(num);

		sum += num;

		push(sum);
	}

	void sub()
	{
		int num, diff;

		pop(diff);
		pop(num);

		diff -= num;

		push(diff);
	}

	void mult()
	{
		int num, prod;

		pop(prod);
		pop(num);

		prod *= num;

		push(prod);
	}

	void div()
	{
		int num, quot;

		pop(num);
		pop(quot);

		quot /= num;

		push(quot);
	}

	void addAll()
	{
		int total = 0;
		int add = 0;
		while (!isEmpty())
		{
			pop(add);
			total += add;
		}

		push(total);
	}

	void multAll()
	{
		int total = 1;
		int mult = 0;
		while (!isEmpty())
		{
			pop(mult);
			total *= mult;
		}

		push(total);
	}
};

int main()
{
	MathStack stack(5);

	cout << "Starting stack: " << endl;
	stack.push(24);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.print();

	cout << "Adding: " << endl;
	stack.add();
	stack.print();

	cout << "Subtracting " << endl;
	stack.sub();
	stack.print();

	cout << "Multiplying " << endl;
	stack.mult();
	stack.print();

	cout << "Dividing " << endl;
	stack.div();
	stack.print();

	cout << "Refilling: " << endl;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.print();

	cout << "Add all: " << endl;
	stack.addAll();
	stack.print();

	cout << "Refilling: " << endl;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.print();

	cout << "Multiplying all: " << endl;
	stack.multAll();
	stack.print();

    return 0;
}

