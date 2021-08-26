#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int> > queries[200001];
vector<int> results(200001, -1);
struct DisjointSet {
    vector<vector<int> > components;
    vector<int> parent;
    DisjointSet(int elements) {
        for(int i = 0; i <= elements; i++) {
            parent.push_back(i);
            components.push_back(vector<int>(1, i));
        }
    }
    int find (int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    void unite(int a, int b, int numEdge) {
        int rep1 = find(a);
        int rep2 = find(b);
        if (rep1 == rep2) return;
        if (components[rep1].size() <= components[rep2].size()) {
            for (int i = 0; i < components[rep1].size(); i++) {
                int firstNum = components[rep1][i];
                for(int j = 0; j < components[rep2].size(); j++) {
                    int secondNum = components[rep2][j];
                    int smaller = min(firstNum, secondNum);
                    int larger = max(firstNum, secondNum);
                    for(int k = 0; k < queries[smaller][larger].size(); k++) {
                        results[queries[smaller][larger][k]] = numEdge;
                    }
                }
            }
            for (int i = 0; i < components[rep1].size(); i++) {
                components[rep2].push_back(components[rep1][i]);
            }
            parent[rep1] = rep2;
        } else {
            unite (b, a, numEdge);
        }
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    int edges[m][2];
    for(int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
   
    for(int i = 0; i < q; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        int smaller = min(c1, c2);
        int bigger = max(c1, c2);
        queries[smaller][bigger].push_back(i);
    }
    DisjointSet dsu(n);
    for(int i = 0; i < m; i++) {
        dsu.unite(edges[i][0], edges[i][1], i + 1);
    }
    for(int i = 0; i < q; i++) {
        cout << results[i] << endl;
    }
    return 0;
}