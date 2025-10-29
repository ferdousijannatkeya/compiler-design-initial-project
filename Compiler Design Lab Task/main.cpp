#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int main() {
    int choice;

    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Numeric Constant Check\n";
        cout << "2. Operator Check\n";
        cout << "3. Comment Check\n";
        cout << "4. Identifier Check\n";
        cout << "5. Array Average\n";
        cout << "6. Array Min/Max\n";
        cout << "7. Full Name Concatenation\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                string s;
                cout << "Enter input: ";
                cin >> s;
                if (isNumericConstant(s))
                    cout << "Numeric Constant\n";
                else
                    cout << "Not Numeric\n";
                break;
            }
            case 2: {
                string s;
                cout << "Enter expression: ";
                cin >> s;
                findOperators(s);
                break;
            }
            case 3: {
                cin.ignore(); // clear buffer
                string s;
                cout << "Enter a line: ";
                getline(cin, s);
                if (isComment(s))
                    cout << "It is a comment line.\n";
                else
                    cout << "Not a comment line.\n";
                break;
            }
            case 4: {
                string s;
                cout << "Enter input: ";
                cin >> s;
                if (isValidIdentifier(s))
                    cout << "Valid Identifier\n";
                else
                    cout << "Not a Valid Identifier\n";
                break;
            }
            case 5: {
                int n;
                cout << "Enter number of elements: ";
                cin >> n;
                int arr[n];
                cout << "Enter " << n << " numbers: ";
                for (int i = 0; i < n; i++)
                    cin >> arr[i];
                cout << "Average = " << findAverage(arr, n) << endl;
                break;
            }
            case 6: {
                int n;
                cout << "Enter number of elements: ";
                cin >> n;
                int arr[n];
                cout << "Enter " << n << " numbers: ";
                for (int i = 0; i < n; i++)
                    cin >> arr[i];
                cout << "Minimum = " << findMin(arr, n) << endl;
                cout << "Maximum = " << findMax(arr, n) << endl;
                break;
            }
            case 7: {
                string firstName, lastName;
                cout << "Enter first name: ";
                cin >> firstName;
                cout << "Enter last name: ";
                cin >> lastName;
                cout << "Full Name = " << getFullName(firstName, lastName) << endl;
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
