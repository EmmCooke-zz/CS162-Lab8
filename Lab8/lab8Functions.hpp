#ifndef LAB_8_FUNCTIONS_HPP
#define LAB_8_FUNCTIONS_HPP

#include <string>
using std::string;

int * readFile(string fileName, int &arraySize);

int findNum(int * arrayIn, int size, int searchValue);

void printResults(int normalArrayPos, int earlyArrayPos,
	int midArrayPos, int endArrayPos);
#endif
