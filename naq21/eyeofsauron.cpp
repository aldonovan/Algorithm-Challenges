#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int parenthesesBeforeFirst = 0;
    int parenthesesAfterSecond = 0;
    int numEyes = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == ')') {
            numEyes++;
        } else {
            if (numEyes == 0) {
                parenthesesBeforeFirst++;
            } else if (numEyes == 2) {
                parenthesesAfterSecond++;
            }
        }
    }
    if (numEyes > 2 || parenthesesBeforeFirst != parenthesesAfterSecond) {
        cout << "fix" << endl;
    } else {
        cout << "correct" << endl;
    }
    return 0;
}
