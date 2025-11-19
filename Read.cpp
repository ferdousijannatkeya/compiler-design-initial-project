#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Check if the sentence contains only letters and spaces
bool isValidSentence(const string& sentence) {
    if (sentence.empty()) return false;
    for (char ch : sentence) {
        if (!isalpha(ch) && ch != ' ') return false;
    }
    return true;
}

int main() {
    ifstream file("Sample.txt");
    if (!file) {
        cout << "Cannot open Sample.txt!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    cout << "Sentence Validation:\n\n";
    while (getline(file, line)) {
        cout << lineNumber++ << ". " << line << " --> "
             << (isValidSentence(line) ? "Valid" : "Invalid") << endl;
    }

    file.close();
    return 0;
}
