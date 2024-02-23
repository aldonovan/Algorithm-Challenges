#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct BIT {
  BIT(int n) : values_(n + 1, 0) {}
  void increment(int i, int delta) {
    while (i < values_.size()) {
      values_[i] += delta;
      i += i & -i;
    }
  }
  int query(int i) {
    int sum = 0;
    while (i > 0) {
      sum += values_[i];
      i -= i & -i;
    }
    return sum;
  }
  // Inclusive
  int query_range(int a, int b) { return query(b) - query(a - 1); }
  vector<int> values_;
};

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> numbers(n);
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  vector<vector<int>> queries;
  for (int i = 0; i < q; i++) {
    int start, end;
    cin >> start >> end;
    --start;
    --end;
    queries.push_back({start, end, i});
  }

  vector<int> answers(q);
  sort(queries.begin(), queries.end(),
       [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
  BIT bit(n);
  int next_processed = 0;
  unordered_map<int, int> value_to_index;
  for (const auto& query : queries) {
    int start = query[0];
    int end = query[1];
    while (next_processed <= end) {
      int val = numbers[next_processed];
      if (auto it = value_to_index.find(val); it != value_to_index.end()) {
        bit.increment(it->second, -1);
      }
      value_to_index[val] = next_processed + 1;
      bit.increment(next_processed + 1, 1);
      ++next_processed;
    }
    answers[query[2]] = bit.query_range(start + 1, end + 1);
  }

  for (int answer : answers) {
    cout << answer << '\n';
  }
}
