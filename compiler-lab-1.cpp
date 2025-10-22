#include <iostream>
#include <string>
using namespace std;

// Function 1: Check Numeric Constant
void checkNumericConstant() {
    string s;
    cout << "Enter input: ";
    cin >> s;

    bool numeric = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '48' || s[i] > '58') {
            numeric = false;
            break;
        }
    }

    if (numeric)
        cout << "Numeric Constant" << endl;
    else
        cout << "Not Numeric" << endl;
}

// Function 2: Check Operators
void checkOperators() {
    string input;
    cout << "Enter an expression: ";
    cin >> input;

    cout << endl;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
            input[i] == '/' || input[i] == '%' || input[i] == '=') {
            cout << "operator: " << input[i] << endl;
        }
    }
}

// Function 3: Check Comments
void checkComments() {
    string input;
    cout << "Enter a line: ";
    cin.ignore(); // clear buffer before getline
    getline(cin, input);

    if (input.substr(0, 2) == "//") {
        cout << "It is a single-line comment." << endl;
    }
    else if (input.substr(0, 2) == "/*" && input.substr(input.size() - 2) == "*/") {
        cout << "It is a multi-line comment." << endl;
    }
    else {
        cout << "It is not a comment line." << endl;
    }
}

// Main function
int main() {
    int choice;
    cout << "Select an option:\n";
    cout << "1. Check Numeric Constant\n";
    cout << "2. Check Operators\n";
    cout << "3. Check Comments\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << endl;

    switch (choice) {
        case 1:
            checkNumericConstant();
            break;
        case 2:
            checkOperators();
            break;
        case 3:
            checkComments();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
