/*
 * DynStack.h
 *
 *  Created on: Feb 20, 2021
 *      Author: amranzazai
 */

// DynStack template
#include <iostream>
template <class T>
class DynStack
{
	private:
		struct StackNode
		{
			T value;
			StackNode *next;
		};

		StackNode *top;

	public:
		DynStack()
			{	top = NULL; }
		void push(T);
		void pop(T &);
		bool isEmpty();
};

//*********************************************************
// Member function push pushes the argument onto          *
// the stack.                                             *
//*********************************************************

template <class T>
void DynStack<T>::push(T num)
{
	StackNode *newNode;

	// Allocate a new node & store Num
	newNode = new StackNode;
	newNode->value = num;

	// If there are no nodes in the list
	// make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = NULL;
	}
	else		// Otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
}

//*********************************************************
// Member function pop pops the value at the top          *
// of the stack off, and copies it into the variable      *
// passed as an argument.                                 *
//*********************************************************

template <class T>
void DynStack<T>::pop(T &num)
{
	StackNode *temp;

	if (isEmpty())
	{
		std::cout << "The stack is empty.\n";
		return;
	}
	else		// pop value off top of stack
	{
		num = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}

//*********************************************************
// Member funciton isEmpty returns true if the stack      *
// is empty, or false otherwise.                          *
//*********************************************************

template <class T>
bool DynStack<T>::isEmpty()
{
	if (!top)
		return true;
	else return false;
}
