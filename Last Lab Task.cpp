#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;


bool isOp(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='='||
           c=='<'||c=='>'||c=='!'||c=='%'||
           c=='&'||c=='|'||c=='^';
}


bool isPunc(char c) {
    return c=='('||c==')'||c=='{'||c=='}'||
           c=='['||c==']'||c==','||c==';';
}


bool isIdentifier(const string& s) {
    if (s.empty()) return false;
    if (!isalpha(s[0]) && s[0] != '_') return false;
    for (char c : s) {
        if (!isalnum(c) && c != '_') return false;
    }
    return true;
}

int main() {
    ifstream file("sample.txt");
    if (!file.is_open()) {
        cout << "Cannot open file.\n";
        return 1;
    }

    cout << "=== SYMBOL TABLE CLASSIFICATION ===\n\n";

    string line;
    while (getline(file, line)) {

        for (size_t i = 0; i < line.size(); i++) {
            char c = line[i];

            // Skip spaces
            if (isspace(c)) continue;

            string token;

            // -------------------------------
            // IDENTIFIER
            // -------------------------------
            if (isalpha(c) || c=='_') {
                while (i < line.size() && (isalnum(line[i]) || line[i]=='_')) {
                    token += line[i];
                    i++;
                }
                i--;

                cout << left << setw(12) << token << " -> Identifier\n";
                continue;
            }

            // -------------------------------
            // NUMBER
            // -------------------------------
            if (isdigit(c)) {
                while (i < line.size() && isdigit(line[i])) {
                    token += line[i];
                    i++;
                }
                i--;

                cout << left << setw(12) << token << " -> Number\n";
                continue;
            }

            // -------------------------------
            // STRING LITERAL
            // -------------------------------
            if (c == '"') {
                token += '"';
                i++;
                while (i < line.size() && line[i] != '"') {
                    token += line[i];
                    i++;
                }
                token += '"';

                cout << left << setw(12) << token << " -> String Literal\n";
                continue;
            }

            // -------------------------------
            // MULTI-CHAR OPERATORS (<< >> == != <= >=)
            // -------------------------------
            if (isOp(c)) {
                token += c;

                if (i+1 < line.size() && isOp(line[i+1])) {
                    token += line[i+1];
                    i++;
                }

                cout << left << setw(12) << token << " -> Operator\n";
                continue;
            }

            // -------------------------------
            // PUNCTUATION
            // -------------------------------
            if (isPunc(c)) {
                token = c;
                cout << left << setw(12) << token << " -> Punctuation\n";
                continue;
            }
        }
    }

    cout << "\n=== ANALYSIS COMPLETE ===\n";
    return 0;
}
