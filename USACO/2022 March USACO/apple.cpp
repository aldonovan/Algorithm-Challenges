#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int>> apples;
    vector<vector<int>> cows;
    for(int i = 0; i < n; i++) {
        int q, t, x, number;
        cin >> q >> t >> x >> number;
    }
    // Thought: We want to ultimately sort by x_i and then greedily process by x_i in increasing order
    // When we are examining a specific apple appearance, we should greedily choose the cows
    // that can reach that location but have the shortest rightward reach. This means that 
    // x_i - t_i >= location - currTime for cows to the left. For cows to the right,
    // this means we need x_i + t_i <= location + currTime. We can sort by x_i + t_i and then keep 
    // a segment tree of least x_i - t_i. We should simply do an upper_bound on the leftward cows to 
    // find the least greater than location - currTime. We can then similarly do query on segment tree
    // and then make a greedy decision. Seems like this will be O(n log n). 
    return 0;
}