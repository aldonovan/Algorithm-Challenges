#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int nums, num;
        unordered_map<int, int> frequencies;
        cin >> nums;
        int largestFreq = 0;
        for(int i = 0; i < nums; i++) {
            cin >> num;
            frequencies[num]++;
            largestFreq = max(largestFreq, frequencies[num]);
        }
        int otherNumbers = nums - largestFreq;
        if(otherNumbers >= largestFreq) {
            cout << nums % 2 << endl;
        } else {
            cout << largestFreq - otherNumbers << endl;
        }
    }
    return 0;
}
