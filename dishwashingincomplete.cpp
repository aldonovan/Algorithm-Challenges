#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
//2019 February USACO Gold
using namespace std;
int main() {
    int n;
    ifstream fin("dishes.in");
    ofstream fout("dishes.out");
    cin >> n;
    vector<int> stackBottoms;
    vector<int> stackTops;
    int maxSeen = -1;
    for(int i = 1; i <= n; i++) {
        int currNumber;
        cin >> currNumber;
        if(currNumber > maxSeen) {
            stackTops.push_back(currNumber);
            stackBottoms.push_back(currNumber);
            maxSeen = currNumber;
        } else {
            int index = upper_bound(stackBottoms.begin(), stackBottoms.end(), currNumber) - stackBottoms.begin();
            if(currNumber < stackTops[index]) {
                stackTops[index] = currNumber;
            } else {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << n << endl;
    return 0;
}