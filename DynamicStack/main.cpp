/*
 * main.cpp
 *
 *  Created on: Feb 20, 2021
 *      Author: amranzazai
 */
#include <iostream>
#include <fstream>
#include "DynStack.h"
using namespace std;

int main()
{
	// Create an input file stream object.
	fstream file1("file1.txt", ios::in);

	// Create an output file stream object.
	fstream file2("file2.txt", ios::out);

	// Create a stack to hold characters.
	DynStack<char> stack;

	char catchChar, ch;

	// Read the characters from file #1
	// and push them onto the stack.
	file1.get(catchChar);
	while (!file1.eof())
	{
		stack.push(catchChar);
		file1.get(catchChar);
	}

	// Close file #1.
	file1.close();

	// Pop the characters from the stack
	// and write them to file #2.
	while (!stack.isEmpty())
	{
		stack.pop(ch);
		file2.put(ch);
	}

	// Close file #2.
	file2.close();

	// Open file #2 again.
	file2.open("file2.txt", ios::in);

	// Read the characters from file #2
	// and display them.
	file2.get(ch);
	while (!file2.eof())
	{
		cout << ch;
		file2.get(ch);
	}

	// Close file #2.
	file2.close();
	cout << endl;

	return 0;
}




