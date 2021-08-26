#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int cSize[1001], parent[1001];

int get(int x) {
    return x == parent[x] ? x : parent[x] = get(parent[x]);
}

void unite(int x, int y) {
    int r1 = get(x);
    int r2 = get(y);
    if(r1 == r2) return;
    if(cSize[r1] > cSize[r2]) swap(r1, r2);
    parent[r1] = r2;
    cSize[r2] += cSize[r1];
}

int getSize(int x) {
    return cSize[get(x)];
}

void initDSU() {
    for(int i = 0; i < 1001; i++) {
        parent[i] = i;
        cSize[i] = 1;
    }
}

bool compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
    return p1.second < p2.second;
}

bool canCommunicate(vector<pair<pair<int, int>, int> > edges, int power, int n) {
    int currIndex = 0;
    while(currIndex < edges.size() && edges[currIndex].second <= power) {
        pair<int, int> vertices = edges[currIndex].first;
        unite(vertices.first, vertices.second);
        currIndex++;
    }
    return getSize(0) == n;
}

int main() {
    int n;
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");
    fin >> n;
    pair<int, int> cows[n];
    for(int i = 0; i < n; i++) {
        int vertex1, vertex2;
        fin >> vertex1 >> vertex2;
        cows[i] = make_pair(vertex1, vertex2);
    }
    vector<pair<pair<int, int>, int> > edges;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int xDiff = cows[j].first - cows[i].first;
            int yDiff = cows[j].second - cows[i].second;
            edges.push_back(make_pair(make_pair(i, j), xDiff*xDiff + yDiff*yDiff));
        }
    }
    sort(edges.begin(), edges.end(), compare);
    int low = 0;
    int high = 1250000000;
    int minCommunicate = high;
    while(low <= high) {
        int mid = low + (high - low)/2;
        initDSU();
        if(canCommunicate(edges, mid, n)) {
            minCommunicate = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    fout << minCommunicate << endl;
    return 0;
}