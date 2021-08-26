#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  char parens[n];
  for(int i = 0; i < n; i++) {
    cin >> parens[i];
  }
  getLongestMatching(n, parens)
  return 0;
}

int getLongestMatching(int n, char parens[]) {
  int longestMatching = 0;
  unordered_map<int, int> balances;
  unordered_map<int, int> matchLengths;
  balances[0] = -1;
  int balance = 0;
  for(int index = 0; index < n; index++) {
    if(parens[index] == '(') {
      balance++;
    } else {
      balance--;
      if(balances.find(balance) != balances.end()) {
        int beforeMatchIndex = balances[balance];
        int currMatchLength = index - beforeMatchIndex;
        if(beforeMatchIndex > 0 && parens[beforeMatchIndex] == ')') {
          currMatchLength += matchLengths[beforeMatchIndex];
        }
        longestMatching = max(longestMatching, currMatchLength);
        matchLengths[index] = currMatchLength;
      }
    }
    balances[balance] = index;
  }
  cout << longestMatching << endl;
}

int getLongestMatchingProvidedSolution(int n, char parens[]) {
  stack<int> leftParens;
  int longestMatching = 0;
  int end = -1;
  for(int i = 0; i < n; i++) {
    if(parens[i] == '(') {
      leftParens.push(i);
    } else if(leftParens.isEmpty()) {
      end = i;
    } else {
      leftParens.pop();
      int beforeMatchIndex = 0;
      if(leftParens.isEmpty()) {
        beforeMatchIndex = end;
      } else {
        beforeMatchIndex = leftParens.peek();
      }
      longestMatching = max(longestMatching, i - beforeMatchIndex);
    }
  }
  cout << longestMatching << endl;
}
