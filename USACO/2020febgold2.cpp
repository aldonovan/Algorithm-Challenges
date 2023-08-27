#include <bits/stdc++.h>
using namespace std;

struct BIT {
  vector<int> values;
  BIT(int n) { values.assign(n + 1, 0); }
  int sum(int right) {
    int total = 0;
    int index = right + 1;
    while (index >= 1) {
      total += values[index];
      index -= index & (-index);
    }
    return total;
  }

  int sum(int left, int right) { return sum(right) - sum(left - 1); }

  void add(int index, int delta) {
    int currIndex = index + 1;
    while (currIndex < values.size()) {
      values[currIndex] += delta;
      currIndex += (currIndex & (-currIndex));
    }
  }
};

long long remainder(int power) {
  long long operand = 2;
  long long remainder = 1;
  while (power > 0) {
    int lastBit = power % 2;
    if (lastBit == 1) {
      remainder = (remainder * operand) % 1000000007;
    }
    operand = (operand * operand) % 1000000007;
    power /= 2;
  }
  return remainder;
}

int main() {
  // There are up to 2N endpoints
  // For each starting point, count number of subsets where that endpoint is
  // start of an interval This is 2^(# of segments that start after current
  // segment)*2^(# of segments end before start) 2^(n - 1 - #segments before
  // that intersect start) -> can use binary indexed tree
  freopen("help.in", "r", stdin);
  freopen("help.out", "w", stdout);
  int n;
  cin >> n;
  pair<int, int> intervals[n];
  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;
    intervals[i] = make_pair(start, end);
  }
  int answer = 0;
  sort(intervals, intervals + n);
  BIT bit(2 * n);
  for (int i = 0; i < n; i++) {
    int numIntersect = bit.sum(intervals[i].first - 1, 2 * n - 1);
    answer = (answer + remainder(n - 1 - numIntersect)) % 1000000007;
    bit.add(intervals[i].second - 1, 1);
  }
  cout << answer << endl;
  return 0;
}