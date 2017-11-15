/*************************************************
* Author: Emmet Cooke
* Date: 11/14/2017
* Description: This file contains the definitions
* for the functions declared in the header file.
* These functions are used for Lab 8 in CS162.
*************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "lab8Functions.hpp"

/*************************************************
* Description: This function reads in the integers
* from the given textfile and places them into
* an array, before returning that array.
*************************************************/
int * readFile(string fileName, int &arraySize)
{
	ifstream fileIn(fileName);
	int num;

	// Determine how many numbers there are in the file
	while (fileIn >> num)
	{
		arraySize++;
	}

	// Declare a new array of that size
	int * returnArray = new int[arraySize];

	// Return to the start of the file
	fileIn.clear();
	fileIn.seekg(0);
	int i = 0;
	// Go through the file and place the numbers into the array
	while (fileIn >> num)
	{
		returnArray[i] = num;
		i++;
	}
	fileIn.close();
	// Returns the int array
	return returnArray;
}

/*************************************************
* Description: This function takes in an array and
* its size and then outputs those to a new file,
* named by the user.
*************************************************/
void outputFile(int * arrayIn, int arraySize)
{	// Get the name for the file
	string fileName;
	getline(cin, fileName);
	ofstream outputFile(fileName);

	// Place the numbers into the array and output them to the console
	cout << "Array values: ";
	for (int i = 0; i < arraySize; i++)
	{
		outputFile << arrayIn[i] << " ";
		cout << arrayIn[i] << " ";
	}
	cout << endl;
	outputFile.close();
}

/*************************************************
* Description: This is a linear search function 
* that goes through the array until the input value
* is found. If found, it returns the position. 
* Otherwise, it returns -1.
*************************************************/
int findNum(int * arrayIn, int size, int searchValue)
{
	for (int i = 0; i < size; i++)
	{	// If the value is found
		if (arrayIn[i] == searchValue)
		{
			return i;
		}
	}
	// If the value is not found
	return -1;
}

/*************************************************
* Description: This is a binary search function
* that finds the input value within the array. It if
* is found, it returns the position. Otherwise, it
* returns -1.
*************************************************/
int findNumBinary(int * arrayIn, int size, int searchValue)
{
	// Variables to mark the indexes to be searched
	int low = 0;
	int high = size - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		int midVal = arrayIn[mid];
		// Value is in the upper half
		if (midVal < searchValue)
		{
			low = mid + 1;
		}	// Value is in the lower half
		else if (midVal > searchValue)
		{
			high = mid - 1;
		}
		else // Value was found
		{
			return mid;
		}
	} // Value was not found
	return -1;
}

/*************************************************
* Description: This function prints the positions
* of the desired number within the four arrays.
* If it was not found the position is replaced with
* "target value not found".
*************************************************/
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

/*************************************************
* Description: This function is the bubbleSort
* function taken from the Lab 8 slides. It goes 
* through the array and swaps lower values with 
* higher ones.
*************************************************/
void bubbleSort(int * arrayIn, int size)
{
	for (int i = (size - 1); i >= 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (arrayIn[j-1] > arrayIn[j])
			{
				// Swap elements at j-1 and j
				int temp = arrayIn[j - 1];
				arrayIn[j - 1] = arrayIn[j];
				arrayIn[j] = temp;
			}
		}
	}
}