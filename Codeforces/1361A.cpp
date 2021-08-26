#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        adj[vertex1].push_back(vertex2);
        adj[vertex2].push_back(vertex1);
    }
    vector<int> rankings[n+1];
    for(int i = 1; i <= n; i++) {
        int ranking;
        cin >> ranking;
        rankings[ranking].push_back(i);
    }
    bool possible = true;
    vector<int> blogOrder;
    vector<int> minTopic(n+1, 1);
    vector<int> used(n+1, false);
    for(int ranking = 1; ranking <= n; ranking++) {
        for(int i = 0; i < rankings[ranking].size(); i++) {
            int currBlog = rankings[ranking][i];
            if(minTopic[currBlog] != ranking) {
                cout << -1 << endl;
                return 0;
            } else {
                blogOrder.push_back(currBlog);
                used[currBlog] = true;
                for(int i = 0; i < adj[currBlog].size(); i++) {
                    int neighbor = adj[currBlog][i];
                    if(minTopic[neighbor] < ranking && !used[neighbor]) {
                        cout << -1 << endl;
                        return 0;
                    } else {
                        minTopic[neighbor] = ranking + 1;
                    }
                }
            }
        }
    }
    for(int i = 0; i < blogOrder.size(); i++) {
        cout << blogOrder[i] << " ";
    }
    return 0;
}