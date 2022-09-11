#include<iostream>

/**
You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

NOTE: "6" is a STRING LITERAL. '6' is a CHAR LITERAL.
*/

using namespace std;

int maximum69num(int num) {
    string s = to_string(num);

    for (int i=0; i < s.size(); i++) {
        if (s[i] == '6') {
            s[i] = '9';
            break;
        }
    }

    return stoi(s);
}

int main() {
    cout << maximum69num(99969) << endl;
}