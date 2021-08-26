#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
/*Find number of pairs of cities x, y so that any path from x to y
must travel through both a and b
*/
void dfs(int vertex, int compNumber, vector<int>adj[], vector<int>& components) {
  components[vertex] = compNumber;
  for(int i = 0; i < adj[vertex].size(); i++) {
    int newVertex = adj[vertex][i];
    if(components[newVertex] == 0) {
      dfs(newVertex, compNumber, adj, components);
    }
  }
}

vector<int> groups(int removed, vector<int> adj[], int n) {
  vector<int> components;
  for(int i = 0; i <= n; i++) {
    components.push_back(0);
  }
  components[removed] = -1;
  int compNumber = 1;
  for(int i = 1; i <= n; i++) {
    if(components[i] == 0) {
      dfs(i, compNumber++, adj, components);
    }
  }
  return components;
}

int main() {
  int t, n, m, a, b, c1, c2;
  cin >> t;
  while(t--) {
    cin >> n >> m >> a >> b;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++) {
      cin >> c1 >> c2;
      adj[c1].push_back(c2);
      adj[c2].push_back(c1);
    }
    vector<int> aGroups = groups(a, adj, n);
    vector<int> bGroups = groups(b, adj, n);
    pii componentInfo[n+1];
    for(int i = 1; i <= n; i++) {
      if(i != a && i != b) {
        componentInfo[i].first = aGroups[i];
        componentInfo[i].second = bGroups[i];
      }
    }
    ll answer = (ll)(n-2)*(n-3)/2;
    map<int, int> oneMatchA;
    map<int, int> oneMatchB;
    map<pii, int> twoMatch;
    for(int i = 1; i <= n; i++) {
      if(i != a && i != b) {
        oneMatchA[componentInfo[i].first]++;
        oneMatchB[componentInfo[i].second]++;
        twoMatch[componentInfo[i]]++;
      }
    }
    for(auto a: oneMatchA) {
      answer -= (ll)a.second*(a.second-1)/2;
    }
    for(auto b: oneMatchB) {
      answer -= (ll)b.second*(b.second-1)/2;
    }
    for(auto t: twoMatch) {
      answer += (ll)t.second*(t.second-1)/2;
    }
    cout << answer << endl;
  }
  return 0;
}
