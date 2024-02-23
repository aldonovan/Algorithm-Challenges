#include <iostream>

using namespace std;
int main() {
  int n;
  cin >> n;
  int largest_so_far = -1;
  int64_t num_operations = 0;
  for (int i = 0; i < n; ++i) {
    int num;
    cin >> num;
    largest_so_far = max(largest_so_far, num);
    num_operations += largest_so_far - num;
  }
  cout << num_operations << '\n';
}