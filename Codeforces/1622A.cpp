#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l1, l2, l3;
        cin >> l1 >> l2 >> l3;
        bool possible = false;
        if (l1 == l2 + l3 || (l2 == l3 && l1 % 2 == 0)) {
            possible = true;
        }
        if (l2 == l1 + l3 || (l1 == l3 && l2 % 2 == 0)) {
            possible = true;
        }
        if (l3 == l1 + l2 || (l1 == l2 && l3 % 2 == 0)) {
            possible = true;
        }
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}