#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
  int n, r1, r2, v;
  cin >> n >> r1 >> r2;
  int i = 1;
  int lastBefore[n + 1];
  while (i <= n) {
    if (i == r1) i++;
    cin >> v;
    lastBefore[i] = v;
    i++;
  }
  int vertex = r2;
  int nextV = lastBefore[vertex];
  while (vertex != r1) {
    int newNext = lastBefore[nextV];
    lastBefore[nextV] = vertex;
    vertex = nextV;
    nextV = newNext;
  }
  for (int i = 1; i <= n; i++) {
    if (i != r2) {
      cout << lastBefore[i] << " ";
    }
  }
  return 0;
}
