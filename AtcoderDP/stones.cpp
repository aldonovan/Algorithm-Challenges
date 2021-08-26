#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> stones;
    vector<bool> winningStates(k+1, false);
    for(int i = 0; i < n; i++) {
        int stone;
        cin >> stone;
        stones.push_back(stone);
    }
    sort(stones.begin(), stones.end());
    for(int numStones = 1; numStones <= k; numStones++) {
        for(int i = 0; i < stones.size() && stones[i] <= numStones; i++) {
            if(!winningStates[numStones - stones[i]]) {
                winningStates[numStones] = true;
                break;
            }
        }
    }
    if(winningStates[k]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}
