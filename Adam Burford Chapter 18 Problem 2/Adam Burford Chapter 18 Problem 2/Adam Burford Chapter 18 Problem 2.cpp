// Adam Burford Chapter 18 Problem 1.cpp : Defines the entry point for the console application.
//

/*
Adam Burford
COP2222 Advanced C++ Programming for Business Mode
Class#5089 Instructor:Westberg

Chapter 18 Problem 2 Linked List
*/

#include <iostream>
using namespace std;

class LinkedList
{
public:
	LinkedList()
	{
		head = nullptr;
	}
	~LinkedList()
	{
		ListNode *currentNode;
		ListNode *nextNode;

		currentNode = head;
		while (currentNode != nullptr)
		{
			nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
	};

	void append(int i)
	{
		ListNode * newNode;
		ListNode * position;

		newNode = new ListNode;
		newNode->value = i;
		newNode->next = nullptr;

		if (!head)
			head = newNode;
		else
		{
			position = head;

			while (position->next)
				position = position->next;

			position->next = newNode;
		}
	}

	void insert(int i)
	{
		ListNode * newNode;
		ListNode * currentPosition;
		ListNode * previousPosition;

		newNode = new ListNode;
		newNode->value = i;

		if (!head)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			currentPosition = head;
			previousPosition = nullptr;

			while (currentPosition != nullptr && currentPosition->value < i)
			{
				previousPosition = currentPosition;
				currentPosition = currentPosition->next;
			}

			if (previousPosition == nullptr)
			{
				head = newNode;
				newNode->next = currentPosition;
			}
			else
			{
				previousPosition->next = newNode;
				newNode->next = currentPosition;
			}
		}
	}

	void remove(int i)
	{
		ListNode * currentNode;
		ListNode * previousNode;

		if (!head)
			return;

		if (head->value == i)
		{
			currentNode = head->next;
			delete head;
			head = currentNode;
		}
		else
		{
			currentNode = head;
			while (currentNode != nullptr && currentNode->value != i)
			{
				previousNode = currentNode;
				currentNode = currentNode->next;
			}

			if (currentNode)
			{
				previousNode->next = currentNode->next;
				delete currentNode;
			}
		}
	}

	void print()
	{
		ListNode * currentNode;

		currentNode = head;

		while (currentNode)
		{
			cout << currentNode->value << " -> ";
			currentNode = currentNode->next;
		}
		cout << "end" << endl;
	}

private:
	struct ListNode
	{
		int value;
		ListNode *next;
	};
	ListNode *head;
};

int main()
{
	LinkedList list;
	list.append(1);
	list.print();
	list.append(3);
	list.print();
	list.append(7);
	list.print();
	list.insert(2);
	list.print();
	list.remove(7);
	list.print();
	return 0;
}

