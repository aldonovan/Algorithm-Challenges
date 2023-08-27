#include <iostream>
using namespace std;
int main() {
    int n;
    int currentNum;
    cin >> n;
    int firstNumber = -1;
    for (int i = 0; i < n; i++) {
        cin >> currentNum;
        if (firstNumber == -1) {
            firstNumber = currentNum;
        } else {
            if (currentNum % firstNumber == 0) {
                cout << currentNum << endl;
                firstNumber = -1;
            }
        }
    }
    return 0;
}