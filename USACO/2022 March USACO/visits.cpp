#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n+1];
    int v[n+1];
    vector<int> inDegree(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> v[i];
        inDegree[a[i]]++;
    }
    vector<bool> visited(n+1, false);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    // We remove vertices with indegree 0 and iterate until we are left with cycles
    long long maxMoos = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        visited[curr] = true;
        maxMoos += v[curr];
        inDegree[a[curr]]--;
        if (inDegree[a[curr]] == 0) {
            q.push(a[curr]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // Trace cycle, find sum and then subtract minimum
            int smallest = v[i];
            maxMoos += v[i];
            visited[i] = true;
            int index = i;
            while (!visited[a[index]]) {
                index = a[index];
                maxMoos += v[index];
                smallest = min(smallest, v[index]);
                visited[index] = true;
            }
            maxMoos -= smallest;
        }
    }
    cout << maxMoos << endl;
    return 0;
}
