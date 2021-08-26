#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
using namespace std;

int sizeC[200000], parent[200000];

int get(int x) {
  return parent[x] == x ? x : parent[x] = get(parent[x]);
}

void unite(int a, int b) {
  int first = get(a);
  int second = get(b);
  if(first == second) return;
  if(sizeC[first] > sizeC[second]) swap(first, second);
  parent[first] = second;
  sizeC[second] += sizeC[first];
}

int main() {
  int n, m;
  ifstream fin ("closing.in");
  ofstream fout ("closing.out");
  fin >> n >> m;
  vector<int> edges[n+1];
  for(int i = 1; i <= n; i++) {
    sizeC[i] = 1;
    parent[i] = i;
  }
  for(int i = 0; i < m; i++) {
    int v1, v2;
    fin >> v1 >> v2;
    edges[v1].push_back(v2);
    edges[v2].push_back(v1);
  }
  int closingOrder[n];
  for(int i = 0; i < n; i++) {
    fin >> closingOrder[i];
  }
  unordered_set<int> open;
  bool connected[n];
  for(int i = n - 1; i >= 0; i--) {
    int currFarm = closingOrder[i];
    open.insert(currFarm);
    for(int i = 0; i < edges[currFarm].size(); i++) {
      if(open.find(edges[currFarm][i]) != open.end()) {
        unite(currFarm, edges[currFarm][i]);
      }
    }
    if(sizeC[get(currFarm)] == n - i) {
      connected[i] = true;
    } else {
      connected[i] = false;
    }
  }
  for(int i = 0; i < n; i++) {
    string isConnected = connected[i] ? "YES": "NO";
    fout << isConnected << endl;
  }
  return 0;
}
