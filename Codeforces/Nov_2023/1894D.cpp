#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, m;
    cin >> n >> m;
    vector<int> original_array(n);
    vector<int> new_array(m);
    for (int j = 0; j < n; ++j) {
      cin >> original_array[j];
    }
    for (int j = 0; j < m; ++j) {
      cin >> new_array[j];
    }
    sort(new_array.begin(), new_array.end(), greater<int>());
    vector<int> final_output;
    int original_index = n - 1;
    int new_index = m - 1;
    while (original_index >= 0 && new_index >= 0) {
      if (new_array[new_index] <= original_array[original_index]) {
        final_output.push_back(new_array[new_index]);
        --new_index;
      } else {
        final_output.push_back(original_array[original_index]);
        --original_index;
      }
    }
    while (original_index >= 0) {
      final_output.push_back(original_array[original_index]);
      --original_index;
    }
    while (new_index >= 0) {
      final_output.push_back(new_array[new_index]);
      --new_index;
    }
    reverse(final_output.begin(), final_output.end());
    for (int num : final_output) {
      cout << num << " ";
    }
    cout << '\n';
  }
}
