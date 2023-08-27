#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <set>
//USACO 2017 December Gold Problem 3
using namespace std;
int main() {
  ifstream fin("hayfeast.in");
  ofstream fout("hayfeast.out");
  long long n, m;
  fin >> n >> m;
  int flavor[n];
  int spiciness[n];
  for(int i = 0; i < n; i++) {
    fin >> flavor[i] >> spiciness[i];
  }
  int minimumSpice = INT_MAX;
  long long currentFlavorSum = 0;
  int startIndex = 0;
  multiset<int> spices;
  for(int endIndex = 0; endIndex < n; endIndex++) {
    currentFlavorSum += flavor[endIndex];
    spices.insert(spiciness[endIndex]);
    while(currentFlavorSum >= m) {
      minimumSpice = min(minimumSpice, *spices.rbegin());
      spices.erase(spices.lower_bound(spiciness[startIndex]));
      currentFlavorSum -= flavor[startIndex];
      startIndex++;
    }
  }
  fout << minimumSpice << endl;
  return 0;
}
