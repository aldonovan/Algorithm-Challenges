#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n;
    cin >> n;
    int numbers[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> numbers[i][j];
        }
    }
    int b[n];
    int a[n];
    int minRowValue = INT_MAX;
    for(int i = 0; i < n; i++) {
        minRowValue = min(minRowValue, numbers[0][i]);
    }
    for(int i = 0; i < n; i++) {
        b[i] = numbers[0][i] - minRowValue;
        a[i] = numbers[i][i] - b[i];
    }
    bool correct = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(numbers[i][j] != (a[i] + b[j])){
                correct = false;
                break;
            }
        }
    }
    if(correct) {
        cout << "Yes" << endl;
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
