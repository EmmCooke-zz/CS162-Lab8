#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "lab8Functions.hpp"

int * readFile(string fileName, int &arraySize)
{
	ifstream fileIn(fileName);
	int num;

	while (fileIn >> num)
	{
		if (num > -1 && num < 10)
		{
			arraySize++;
		}
	}

	int * returnArray = new int[arraySize];

	fileIn.clear();
	fileIn.seekg(0);
	int i = 0;
	while (fileIn >> num)
	{
		if (num > -1 && num < 10)
		{
			returnArray[i] = num;
		}
		i++;
	}
	fileIn.close();

	return returnArray;
}

int findNum(int * arrayIn, int size, int searchValue)
{
	for (int i = 0; i < size; i++)
	{
		if (arrayIn[i] == searchValue)
		{
			return i;
		}
	}
	return -1;
}

void printResults(int normalArrayPos, int earlyArrayPos,
	int midArrayPos, int endArrayPos)
{
	// Output the position in the normal array
	if (normalArrayPos != -1)
	{
		cout << "numbers.txt: " << normalArrayPos << endl;
	}
	else
	{
		cout << "numbers.txt: target value not found" << endl;
	}

	// Output the position in the early array
	if (earlyArrayPos != -1)
	{
		cout << "early.txt  : " << earlyArrayPos << endl;
	}
	else
	{
		cout << "early.txt  : target value not found" << endl;
	}

	// Output the position in the middle array
	if (midArrayPos != -1)
	{
		cout << "middle.txt : " << midArrayPos << endl;
	}
	else
	{
		cout << "middle.txt : target value not found" << endl;
	}

	// Output the position in the end array
	if (endArrayPos != -1)
	{
		cout << "end.txt    : " << endArrayPos << endl;
	}
	else
	{
		cout << "end.txt    : target value not found" << endl;
	}

}