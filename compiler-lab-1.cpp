#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a line: ";
    getline(cin, input); // to take the whole line including spaces

    if (input.substr(0, 2) == "//") {
        cout << "It is a single-line comment.";
    }
    else if (input.substr(0, 2) == "/*" && input.substr(input.size() - 2) == "*/") {
        cout << "It is a multi-line comment.";
    }
    else {
        cout << "It is not a comment line.";
    }

    return 0;
}

