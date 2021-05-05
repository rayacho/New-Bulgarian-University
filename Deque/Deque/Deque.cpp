#include <iostream>

using namespace std;

#define MAX_SIZE 256

class Deque
{
private:
	int deque[MAX_SIZE];
	int front;
	int rear;
	int size;
public:
	Deque();
	Deque(int);

	bool isEmpty();
	bool isFull();

	void insertFront(int);
	void insertRear(int);

	void removeFront();
	void removeRear();

	int getFront();
	int getRear();

	void print();
};

Deque::Deque()
{
	front = -1;
	rear = -1;
	size = 1;
}

Deque::Deque(int s)
{
	front = -1;
	rear = -1;
	size = s;
}

bool Deque::isEmpty()
{
	return front == -1;
}

bool Deque::isFull()
{
	return (front == 0 && rear == size - 1) || (front == rear + 1);
}

void Deque::insertFront(int number)
{
	if (isFull())
	{
		cout << "You have reached the limit of the deque.\n";
		return;
	}

	if (isEmpty())
	{
		front = 0;
		rear = 0;
	}
	else if (front == 0)
	{
		front = size - 1;
	}
	else
	{
		front--;
	}

	deque[front] = number;
}

void Deque::insertRear(int number)
{
	if (isFull())
	{
		cout << "You have reached the limit of the deque.\n";
		return;
	}

	if (isEmpty())
	{
		front = 0;
		rear = 0;
	}
	else if (rear == size - 1)
	{
		rear = 0;
	}
	else
	{
		rear++;
	}

	deque[rear] = number;
}

void Deque::removeFront()
{
	if (isEmpty())
	{
		cout << "Deletion is not possible.\n";
		return;
	}

	cout << "The number that was deleted from the deque is " << deque[front] << ".\n";

	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size - 1)
	{
		front = 0;
	}
	else
	{
		front++;
	}
}

void Deque::removeRear()
{
	if (isEmpty())
	{
		cout << "Deletion is not possible.\n";
		return;
	}

	cout << "The number that was deleted from the deque is " << deque[rear] << ".\n";

	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (rear == 0)
	{
		rear = size - 1;
	}
	else
	{
		rear--;
	}
}

int Deque::getFront()
{
	return deque[front];
}

int Deque::getRear()
{
	return deque[rear];
}

void Deque::print()
{
	if (isEmpty())
	{
		cout << "The deque is currently empty.\n";
	}
	else
	{
		cout << "The current first element of the deque is " << getFront() << ".\n";
		cout << "The current last element of the deque is " << getRear() << ".\n";
	}
}

int main()
{
	int size;
	while (true)
	{
		cout << "Enter the capacity of the deque (an integer between 1 and " << MAX_SIZE << "): ";
		cin >> size;

		if (size >= 1 && size < MAX_SIZE)
		{
			break;
		}
	}

	Deque deque(size);

	int option;
	cout << "Choose one of the following options:" << endl;
	cout << "1. Add a number to the beginning" << endl;
	cout << "2. Add a number to the end" << endl;
	cout << "3. Remove the first element" << endl;
	cout << "4. Remove the last element" << endl;
	cout << "0. Exit" << endl;

	while (true)
	{
		cout << "Choose an option: ";
		cin >> option;

		if (option == 0)
		{
			break;
		}

		int number;

		switch (option)
		{
		case 1:
			cout << "Enter a number: ";
			cin >> number;
			deque.insertFront(number);
			break;
		case 2:
			cout << "Enter a number: ";
			cin >> number;
			deque.insertRear(number);
			break;
		case 3:
			deque.removeFront();
			break;
		case 4:
			deque.removeRear();
			break;
		}

		deque.print();
		cout << endl;
	}

	return 0;
}