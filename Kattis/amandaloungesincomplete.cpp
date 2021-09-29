#include <bits/stdc++.h>
using namespace std;
// https://open.kattis.com/problems/amanda

vector<int> coloring(200001, -1);
vector<int> adj[200001];

int lounges = 0;

set<int> processed;
set<int> visited;

bool dfs (int vertex, int color) {
    if (coloring[vertex] != -1) return true;
    coloring[vertex] = color;
    visited.insert(vertex);
    for (int neighbor : adj[vertex]) {
        if (coloring[neighbor] == coloring[vertex]) {
            return false;
        }
        if (!dfs(neighbor, -1*color + 1)) {
            return false;
        }
    }
    return true;
}

void cleanup(bool success) {
    for (int vertex : visited) {
        coloring[vertex] = -1;
        if (success) {
            processed.insert(vertex);
        }
    }
    visited.clear();
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 2) {
            if (coloring[a] == 0 || coloring[b] == 0) {
                cout << "impossible" << endl;
                return 0;
            }
            coloring[a] = 1;
            coloring[b] = 1;
        } else if (c == 0) {
            if (coloring[a] == 1 || coloring[b] == 1) {
                cout << "impossible" << endl;
                return 0;
            }
            coloring[a] = 0;
            coloring[b] = 0;
        } else if (c == 1) {
            if ((coloring[a] == 0 && coloring[b] == 0) || (coloring[a] == 1 && coloring[b] == 1)) {
                cout << "impossible" << endl;
                return 0;
            }
            if (coloring[a] == 0) {
                coloring[b] = 1;
            } else if (coloring[a] == 1) {
                coloring[b] = 0;
            } else if (coloring[b] == 0) {
                coloring[a] = 1;
            } else if (coloring[b] == 1) {
                coloring[a] = 0;
            } else {
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }
    }
    int numLounges = 0;
    for (int i = 1; i <= n; i++) {
        if (coloring[i] == 1) {
            numLounges++;
        } else if (coloring[i] == -1 && processed.find(i) == processed.end()) {
            int smallestNumber = INT_MAX;
            bool result1 = dfs(i, 1);
            if (result1) {
                smallestNumber = min(smallestNumber, lounges);
            }
            lounges = 0;
            cleanup(result1);
            bool result2 = dfs(i, 0);
            if (result2) {
                smallestNumber = min(smallestNumber, lounges);
            }
            cleanup(result2);
            if (!result1 && !result2) {
                cout << "impossible" << endl;
                return 0;
            }
            numLounges += smallestNumber;
        }
    }
    cout << numLounges << endl;
    return 0;
}
