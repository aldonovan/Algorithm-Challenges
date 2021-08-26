#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int qPerm[n];
        for(int j = 0; j < n; j++) {
            cin >> qPerm[j];
        }
        //Find lexicographically minimal and maximal permutations
        set<int> minComplement;
        set<int> maxComplement;
        vector<int> minPerm;
        vector<int> maxPerm;
        for(int k = 1; k <= n; k++) {
            if(k != qPerm[0]) {
                minComplement.insert(k);
                maxComplement.insert(k);            
            } 
        }
        minPerm.push_back(qPerm[0]);
        maxPerm.push_back(qPerm[0]);
        for(int index = 1; index < n; index++) {
            if(qPerm[index] > qPerm[index - 1]) {
                minPerm.push_back(qPerm[index]);
                maxPerm.push_back(qPerm[index]);
                minComplement.erase(qPerm[index]);
                maxComplement.erase(qPerm[index]);
            } else {
                int minNext = *minComplement.begin();
                minPerm.push_back(minNext);
                minComplement.erase(minNext);
                auto it = maxComplement.lower_bound(qPerm[index]);
                it--;
                int maxNext = *it;
                maxPerm.push_back(maxNext);
                maxComplement.erase(maxNext);
            }
        }
        for(int i = 0; i < n; i++) {
            cout << minPerm[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < n; i++) {
            cout << maxPerm[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
