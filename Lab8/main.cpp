/*************************************************
* Program: Lab 8 - Searching and Sorting
* Author: Emmet Cooke
* Date: 11/14/2017
* Description: This is the main file for Lab 8. It
* first arranges the value from for text files into
* individual arrays and then asks the user for a 
* value to be found in them. It sorts and then outputs
* the array values to files as specified by the user.
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
		cout << "Please enter an positive integer to find by linear search in the files: ";
		getline(cin, validateInput);
		number = getInt(validateInput);
		if (number < 0)
		{
			cout << "Please enter a positive int." << endl;
		}
	} while (number < 0);

	// Find the number within the arrays with a linear search
	int numPosNormalArray = findNum(normalArray, normalArraySize, number);
	int numPosEarlyArray = findNum(earlyArray, earlyArraySize, number);
	int numPosMidArray = findNum(midArray, midArraySize, number);
	int numPosEndArray = findNum(endArray, endArraySize, number);

	// Print the results
	printResults(numPosNormalArray, numPosEarlyArray, numPosMidArray, numPosEndArray);

	// Sort the four arrays
	// This bubble sort is taken from the slides in the Week 8 readings
	bubbleSort(normalArray, normalArraySize);
	bubbleSort(earlyArray, earlyArraySize);
	bubbleSort(midArray, midArraySize);
	bubbleSort(endArray, endArraySize);

	// Output the arrays into files
	string fileName;
	
	// Normal array
	cout << "What would you like the name of the file to be for the sorted Normal Array? ";
	outputFile(normalArray, normalArraySize);

	// Early Array
	cout << "What would you like the name of the file to be for the sorted Early Array? ";
	outputFile(earlyArray, earlyArraySize);

	// Mid Array
	cout << "What would you like the name of the file to be for the sorted Middle Array? ";
	outputFile(midArray, midArraySize);

	// End Array
	cout << "What would you like the name of the file to be for the sorted End Array? ";
	outputFile(endArray, endArraySize);


	// Get a number from the user and find it with binary search
	do
	{
		cout << "Please enter an positive integer to find by binary search in the files: ";
		getline(cin, validateInput);
		number = getInt(validateInput);
		if (number < 0)
		{
			cout << "Please enter a positive int." << endl;
		}
	} while (number < 0);

	// Find the number within the arrays with a binary search
	numPosNormalArray = findNumBinary(normalArray, normalArraySize, number);
	numPosEarlyArray = findNumBinary(earlyArray, earlyArraySize, number);
	numPosMidArray = findNumBinary(midArray, midArraySize, number);
	numPosEndArray = findNumBinary(endArray, endArraySize, number);

	// Print the results
	printResults(numPosNormalArray, numPosEarlyArray, numPosMidArray, numPosEndArray);

	// Free the memory
	delete[] normalArray;
	delete[] earlyArray;
	delete[] midArray;
	delete[] endArray;
	
	return 0;
}