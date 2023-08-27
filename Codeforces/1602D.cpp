#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n+1];
    int b[n+1];
    pair<int, int> predecessor[n+1];
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    queue<int> positions;
    positions.push(n);
    int firstAvailable = n - 1;
    int numJumps = 0;
    while (!positions.empty() && !visited[0]) {
        int numPositions = positions.size();
        for (int i = 0; i < numPositions; i++) {
            int currPosition = positions.front();
            positions.pop();
            if (currPosition - a[currPosition] <= 0) {
                predecessor[0] = make_pair(0, currPosition);
                visited[0] = true;
                break;
            }
            for (int jump = firstAvailable; jump >= currPosition - a[currPosition]; jump--) {
                int destination = jump + b[jump];
                if (!visited[destination]) {
                    visited[destination] = true;
                    predecessor[destination] = make_pair(jump, currPosition);
                    positions.push(destination);
                }
                firstAvailable--;
            }
        }
        numJumps++;
    }
    if (!visited[0]) {
        cout << -1 << endl;
    } else {
        cout << numJumps << endl;
        int jumps[numJumps];
        int currPosition = 0;
        int index = 0;
        while(currPosition != n) {
            jumps[index] = predecessor[currPosition].first;
            currPosition = predecessor[currPosition].second;
            index++;
        }
        for (int index = numJumps - 1; index >= 0; index--) {
            cout << jumps[index] << " ";
        }
        cout << endl;
    }
    return 0;
}
