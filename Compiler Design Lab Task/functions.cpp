#include "functions.h"
#include <iostream>
using namespace std;

// Task 1: Numeric constant
bool isNumericConstant(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

// Task 2: Operators
void findOperators(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' ||
            s[i] == '/' || s[i] == '%' || s[i] == '=') {
            count++;
            cout << "operator" << count << ": " << s[i] << endl;
        }
    }
}

// Task 3: Comments
bool isComment(string s) {
    if (s.substr(0, 2) == "//")
        return true;
    else if (s.substr(0, 2) == "/*" && s.substr(s.size() - 2) == "*/")
        return true;
    else
        return false;
}

// Task 4: Identifier
bool isValidIdentifier(string s) {
    if (!((s[0] >= 'A' && s[0] <= 'Z') ||
          (s[0] >= 'a' && s[0] <= 'z') ||
          s[0] == '_'))
        return false;

    for (int i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= '0' && s[i] <= '9') ||
              s[i] == '_'))
            return false;
    }
    return true;
}

// Task 5: Array Average
float findAverage(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (float)sum / n;
}

// Task 6: Array Min/Max
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

// Task 7: Full Name Concatenation
string getFullName(string firstName, string lastName) {
    return firstName + " " + lastName;
}

