#include <iostream>
using namespace std;
int main() {
    int t, n;
    string path;
    cin >> t;
    while(t--) {
        cin >> n >> path;
        for(int i = 0; i < path.length(); i++) {
            if(path[i] == 'S') {
                path[i] = 'E';
            } else {
                path[i] = 'S';
            }
        }
        cout << path << endl;
    }
    return 0;
}
