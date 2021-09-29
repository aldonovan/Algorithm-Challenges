#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int breeds[n];
    for (int i = 0; i < n; i++) {
        cin >> breeds[i];
    }
    string canCommunicate[k];
    for (int i = 0; i < k; i++) {
        cin >> canCommunicate[i];
    }
    // 0-1 BFS
    deque<pair<int, int> > states;
    states.push_front(make_pair(0, breeds[0]));
    vector<vector<int> > costs(n, vector<int>(k, -1));
    costs[0][breeds[0] - 1] = 0;
    while (!states.empty()) {
        pair<int, int> state = states.front();
        states.pop_front();
        int currIndex = state.first;
        int lastBreed = state.second;
        int currBreed = breeds[currIndex];
        if (canCommunicate[lastBreed - 1][currBreed - 1] == '1') {
            if (currIndex == n - 1) {
                cout << costs[n - 1][lastBreed - 1] << endl;
                return 0;
            }
            if (costs[currIndex][currBreed - 1] == -1) {
                states.push_front(make_pair(currIndex, currBreed));
                costs[currIndex][currBreed - 1] = costs[currIndex][lastBreed - 1];
            }
        }
        if (currIndex > 0 && costs[currIndex - 1][lastBreed - 1] == -1) {
            states.push_back(make_pair(currIndex - 1, lastBreed));
            costs[currIndex - 1][lastBreed - 1] = costs[currIndex][lastBreed - 1] + 1;
        }
        if (currIndex < n - 1 && costs[currIndex + 1][lastBreed - 1] == -1) {
            states.push_back(make_pair(currIndex + 1, lastBreed));
            costs[currIndex + 1][lastBreed - 1] = costs[currIndex][lastBreed - 1] + 1;
        }
    }
    cout << -1 << endl;
    return 0;
}
