/*************************************************
* Program: Lab 8 - Searching and Sorting
* Author: Emmet Cooke
* Date: 11/14/2017
* Description: 
*************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "lab8Functions.hpp"
#include "validateInput.hpp"

int main()
{
	// Arrays to hold the numbers from the 4 files
	int normalArraySize = 0;
	int * normalArray = readFile("numbers.txt", normalArraySize);
	int earlyArraySize = 0;
	int * earlyArray = readFile("early.txt", earlyArraySize);
	int midArraySize = 0;
	int * midArray = readFile("middle.txt", midArraySize);
	int endArraySize = 0;
	int * endArray = readFile("end.txt", endArraySize);

	// Get a number to search from the user
	int number;
	string validateInput;
	do
	{
		cout << "Please enter an positive integer to find in the files: ";
		getline(cin, validateInput);
		number = getInt(validateInput);
		if (number < 0)
		{
			cout << "Please enter a positive int." << endl;
		}
	} while (number < 0);

	// Find the number within the files
	int numPosNormalArray = findNum(normalArray, normalArraySize, number);
	int numPosEarlyArray = findNum(earlyArray, earlyArraySize, number);
	int numPosMidArray = findNum(midArray, midArraySize, number);
	int numPosEndArray = findNum(endArray, endArraySize, number);

	// Print the results
	printResults(numPosNormalArray, numPosEarlyArray, numPosMidArray, numPosEndArray);

	// Sort and Output the four arrays


	// Free the memory
	delete[] normalArray;
	delete[] earlyArray;
	delete[] midArray;
	delete[] endArray;
	return 0;
}