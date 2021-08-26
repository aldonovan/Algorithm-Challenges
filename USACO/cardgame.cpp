#include <iostream>
#include <fstream>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  ifstream fin("cardgame.in");
  ofstream fout("cardgame.out");
  fin >> n;
  unordered_set<int> numbers;
  int highOpponent[n/2];
  int lowOpponent[n/2];
  for(int i = 0; i < n/2; i++) {
    fin >> highOpponent[i];
    numbers.insert(highOpponent[i]);
  }
  for(int i = 0; i < n/2; i++) {
    fin >> lowOpponent[i];
    numbers.insert(lowOpponent[i]);
  }
  sort(highOpponent, highOpponent + n/2);
  sort(lowOpponent, lowOpponent + n/2);
  int cards[n];
  int index = 0;
  for(int i = 1; i <= 2*n; i++) {
    if(numbers.find(i) == numbers.end()) {
      cards[index] = i;
      index++;
    }
  }
  int wins = 0;
  int myIndex = n - 1;
  int opIndex = n/2 - 1;
  while(opIndex >= 0) {
    if(cards[myIndex] > highOpponent[opIndex]) {
      wins++;
      myIndex--;
    }
    opIndex--;
  }
  myIndex = 0;
  opIndex = 0;
  while(opIndex < n/2) {
    if(cards[myIndex] < lowOpponent[opIndex]) {
      wins++;
      myIndex++;
    }
    opIndex++;
  }
  fout << wins << endl;
  return 0;
}
