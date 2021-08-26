#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
long long dp[100001][4];
int numWays(int currVertex, int currColor, int prevVertex, vector<int> edges[], int colors[]) {
    cout << dp[currVertex][currColor] << endl;
    if(colors[currVertex] != 0 && currColor != colors[currVertex]) return 0;
    if(dp[currVertex][currColor] >= 0) return dp[currVertex][currColor];
    dp[currVertex][currColor] = 1;
    for(int i = 0; i < edges[currVertex].size(); i++) {
        int nextVertex = edges[currVertex][i];
        if(nextVertex == prevVertex) continue;
        long long sumColorings = 0;
        for(int color = 1; color <= 3; color++) {
            if(color != currColor) {
                sumColorings += numWays(nextVertex, color, currVertex, edges, colors);
            }
        }
        dp[currVertex][currColor] *= sumColorings;
        dp[currVertex][currColor] %= 1000000007;
    }
    return dp[currVertex][currColor];
}

int main() {
    ifstream fin("barnpainting.in");
    //ofstream fout("barnpainting.out");
    int n, k;
    fin >> n >> k;
    vector<int> edges[n+1];
    int colors[n+1];
    int dp[n+1][4];
    for(int i = 0; i <= n; i++) {
        colors[i] = 0;
        for(int j = 1; j <= 3; j++) {
            dp[i][j] = -1;
        }
    }
    for(int i = 0; i < n - 1; i++) {
        int vertex1, vertex2;
        fin >> vertex1 >> vertex2;
        edges[vertex1].push_back(vertex2);
        edges[vertex2].push_back(vertex1);
    }
    for(int i = 0; i < k; i++) {
        int vertex, color;
        fin >> vertex >> color;
        colors[vertex] = color;
    }
    cout << numWays(1, 1, 0, edges, colors) << endl;
    return 0;
}