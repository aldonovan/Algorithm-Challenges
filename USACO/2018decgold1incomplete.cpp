#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    // Run Dijkstra's algorithm twice. First run it with the original graph.
    // Then we remove all edges from N and add edges from N to each haybale
    // with weight equal to mindist(k) - y_k where we get mindist from last step.
    // Then we run Dijkstra's again on the new graph and return 1 for each vertex
    // where the minimum distance <= than in the first Dijkstra run.
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int> > adj[n];
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a-1].push_back(make_pair(b-1, w));
        adj[b-1].push_back(make_pair(a-1, w));
    }
    vector<int> yumminess(n, -1);
    for (int i = 0; i < k; i++) {
        int index, value;
        cin >> index >> value;
        yumminess[index - 1] = value;
    }
    priority_queue<pair<ll, int> > pq;
    vector<long long> distances(n, LLONG_MAX);
    distances[0] = 0;
    pq.push({0, 0});

    return 0;
}