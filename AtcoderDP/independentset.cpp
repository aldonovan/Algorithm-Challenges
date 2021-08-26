#include <iostream>
#include <vector>
using namespace std;
//DP on trees
long long numWaysToColor(int vertex, int color, int parent, vector<int> edges[], int memoColors[][2]) {
    long long numColorings = 1;
    if(memoColors[vertex][color] != 0) return memoColors[vertex][color];
    for(int i = 0; i < edges[vertex].size(); i++) {
        int neighbor = edges[vertex][i];
        if(neighbor == parent) continue;
        int numNeighborColorings = numWaysToColor(neighbor, 1, vertex, edges, memoColors);
        if(color == 1) {
            numNeighborColorings += numWaysToColor(neighbor, 0, vertex, edges, memoColors);
        }
        numColorings *= numNeighborColorings;
        numColorings %= 1000000007;
    }
    memoColors[vertex][color] = numColorings;
    return numColorings;
}

int main() {
    int n;
    cin >> n;
    vector<int> edges[n];
    for(int i = 0; i < n - 1; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        edges[vertex1-1].push_back(vertex2-1);
        edges[vertex2-1].push_back(vertex1-1);
    }
    int memoColors[n][2];
    for(int i = 0; i < n; i++) {
        memoColors[i][0] = 0;
        memoColors[i][1] = 0;
    }
    //Arbitrarily root the tree at 0
    long long totalColorings = (numWaysToColor(0, 0, -1, edges, memoColors) + numWaysToColor(0, 1, -1, edges, memoColors)) % 1000000007;
    cout << totalColorings << endl;
    return 0;
}