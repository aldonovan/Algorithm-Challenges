#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
//This is an O(n log n) solution but I think multiple too high so should change to segment tree
bool comp(const pair<int,long long> &pair1, const pair<int, long long> &pair2) {
    return pair1.first < pair2.first;
}

int main() {
    int n;
    cin >> n;
    int heights[n];
    int beauty[n];
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> beauty[i];
    }
    set<pair<int, long long> > increasingHeights;
    increasingHeights.insert(make_pair(heights[0], (long long)beauty[0]));
    for(int index = 1; index < n; index++) {
        auto it = upper_bound(increasingHeights.begin(), increasingHeights.end(), make_pair(heights[index], beauty[index]), comp);
        long long additionalBeauty = 0;
        if(it != increasingHeights.begin()) {
            it--;
            additionalBeauty = it->second;
            if(it->first == heights[index]) {
                auto newIt = it;
                newIt++;
                increasingHeights.erase(it);
                it = newIt;
            } else {
                it++;
            }
        } 
        while(it != increasingHeights.end() && it->second <= beauty[index] + additionalBeauty) {
            auto newIt = it;
            newIt++;
            increasingHeights.erase(it);
            it = newIt;
        }
        increasingHeights.insert(make_pair(heights[index], beauty[index] + additionalBeauty));
    }
    cout << increasingHeights.rbegin()->second << endl;
    return 0;
}
