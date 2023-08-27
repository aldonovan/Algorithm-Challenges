#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    int numFalse = 0;
    int lastFalse = 0;
    vector<bool> slots;
    for(int i = 0; i < n/2; i++) {
        char firstChar = s[2*i];
        char secondChar = s[2*i + 1];
        if (firstChar == 'G' && secondChar == 'H') {
            slots.push_back(false);
            numFalse++;
            lastFalse = slots.size() - 1;
        } else if (firstChar == 'H' && secondChar == 'G') {
            slots.push_back(true);
        }
    }
    if (numFalse == 0) {
        cout << 0 << endl;
    } else {
        int numReversals = 1;
        bool currBool = false;
        for (int index = lastFalse - 1; index >= 0; index--) {
            if (slots[index] != currBool) {
                numReversals++;
                currBool = slots[index];
            }
        }
        cout << numReversals << endl;
    }
}
