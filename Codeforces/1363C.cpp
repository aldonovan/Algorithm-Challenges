#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, x;
        cin >> n >> x;
        int xDegree = 0;
        for(int j = 0; j < n - 1; j++) {
            int vertex1, vertex2;
            cin >> vertex1 >> vertex2;
            if(vertex1 == x || vertex2 == x) xDegree++;
        }
        if(n % 2 == 0 || xDegree <= 1) {
            cout << "Ayush" << endl;
        } else {
            cout << "Ashish" << endl;
        }
    }
    return 0;
}