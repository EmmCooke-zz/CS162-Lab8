/*************************************************
* Author: Emmet Cooke
* Date: 11/14/2017
* Description: This is a header file containing the 
* function declarations for use in Lab 8 of CS 162.
*************************************************/
#ifndef LAB_8_FUNCTIONS_HPP
#define LAB_8_FUNCTIONS_HPP

#include <string>
using std::string;

// Reads a text file and gets the integers from within it
int * readFile(string fileName, int &arraySize);

// Outputs the numbers in an array to a text file
void outputFile(int * arrayIn, int arraySize);

// Finds the number in an array by linear search
int findNum(int * arrayIn, int size, int searchValue);

// Finds the numbers in an array by binary search
int findNumBinary(int * arrayIn, int size, int searchValue);

// Prints the results of the four arrays
void printResults(int normalArrayPos, int earlyArrayPos,
	int midArrayPos, int endArrayPos);

// This function is taken from the CH 8 readings page of CS162,
// specifically the Sort-Bubble.pdf file
void bubbleSort(int * arrayIn, int size);
#endif
