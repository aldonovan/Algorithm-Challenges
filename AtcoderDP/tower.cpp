#include <iostream>
#include <vector>
using namespace std;

bool blockOrder(vector<int> block1, vector<int> block2) {
    return block1[0] + block1[1] < block2[0] + block2[1];
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > blocks;
    for(int i = 0; i < n; i++) {
        int weight, solidness, value;
        cin >> weight >> solidness >> value;
        vector<int> block;
        block.push_back(weight);
        block.push_back(solidness);
        block.push_back(value);
        blocks.push_back(block); 
    }
    sort(blocks.begin(), blocks.end(), blockOrder);
    int maxWeight = 20001;
    vector<long long> maxValues(maxWeight, 0);
    for(int i = 0; i < n; i++) {
        for(int weight = blocks[i][0] + blocks[i][1]; weight >= blocks[i][0]; weight--) {
            maxValues[weight] = max(maxValues[weight], maxValues[weight - blocks[i][0]] + blocks[i][2]);
        }
    }
    long long highestValue = 0;
    for(int i = 0; i < maxValues.size(); i++) {
        highestValue = max(highestValue, maxValues[i]);
    }
    cout << highestValue << endl;
    return 0;
}
