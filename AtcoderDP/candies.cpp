#include <iostream>
#include <vector>
using namespace std;
//Similar to knapsack DP but uses prefix sums to speed up computations

int main() {
    int n, k;
    cin >> n >> k;
    int candies[n];
    for(int i = 0; i < n; i++) {
        cin >> candies[i];
    }
    vector<int> distributions(k+1, 0);
    vector<int> prefixSums(k+1, 1);
    distributions[0] = 1;
    for(int index = 0; index < n; index++) {
        vector<int> newDistributions(k+1, 0);
        vector<int> newPrefixSums(k+1, 0);
        for(int numCandies = 0; numCandies <= k; numCandies++) {
            int minNumber = numCandies - candies[index];
            int newWays = prefixSums[numCandies];
            if(minNumber > 0) newWays -= prefixSums[minNumber - 1];
            if(newWays < 0) newWays += 1000000007;
            newWays %= 1000000007;
            newDistributions[numCandies] = newWays;
            newPrefixSums[numCandies] = newWays;
            if(numCandies > 0) {
                newPrefixSums[numCandies] += newPrefixSums[numCandies - 1];
                newPrefixSums[numCandies] %= 1000000007;
            }
        }
        distributions = newDistributions;
        prefixSums = newPrefixSums;
    }
    cout << distributions[k] << endl;
    return 0;
}
