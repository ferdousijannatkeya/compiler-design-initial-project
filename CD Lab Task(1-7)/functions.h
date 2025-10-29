#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;

// Task 1: Numeric Constant
bool isNumericConstant(string s);

// Task 2: Operators
void findOperators(string s);

// Task 3: Comments
bool isComment(string s);

// Task 4: Identifier
bool isValidIdentifier(string s);

// Task 5: Array Average
float findAverage(int arr[], int n);

// Task 6: Array Min/Max
int findMin(int arr[], int n);
int findMax(int arr[], int n);

// Task 7: Full Name Concatenation
string getFullName(string firstName, string lastName);

#endif

