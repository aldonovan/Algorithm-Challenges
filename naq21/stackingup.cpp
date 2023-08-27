#include <iostream>
#include <algorithm>
using namespace std;

pair<string, int> getSequence(int n) {
    if (n == 1) {
        return {"1", 0};
    }
    if (n == 2) {
        return {"11+", 1};
    }
    pair<string, int> half = getSequence(n/2);
    if (n % 2 == 0) {
        string seq = half.first + "d+";
        return {seq, half.second + 1};
    } else {
        string seq = half.first + "d+1+";
        return {seq, half.second + 2};
    }
}

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    string operations = "";
    int additions = 0;
    for (int index = n - 1; index >= 0; index--) {
        pair<string, int> sequence = getSequence(nums[index] + additions);
        additions += sequence.second;
        reverse(sequence.first.begin(), sequence.first.end());
        operations += sequence.first;
    }
    reverse(operations.begin(), operations.end());
    cout << operations << endl;
    return 0;
}
