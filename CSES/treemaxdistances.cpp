#include <bits/stdc++.h>
using namespace std;
vector<int> edges[200000];
int heights[200000];
int verticalDistances[200000];

int calculateHeights(int currNode, int parent) {
    int maxChildHeight = -1;
    for(int child: edges[currNode]) {
        if(child != parent) {
            maxChildHeight = max(maxChildHeight, calculateHeights(child, currNode));
        }
    }
    heights[currNode] = maxChildHeight + 1;
    return heights[currNode];
}

void calculateVerticalDistances(int currNode, int parent) {
    int largestChildHeight = -1;
    int secondLargestChildHeight = -1;
    for(int child: edges[currNode]) {
        if(child != parent) {
            if(heights[child] > largestChildHeight) {
                secondLargestChildHeight = largestChildHeight;
                largestChildHeight = heights[child];
            } else if(heights[child] > secondLargestChildHeight) {
                secondLargestChildHeight = heights[child];
            }
        }
    }
    for(int child: edges[currNode]) {
        if(child != parent) {
            if(heights[child] == largestChildHeight) {
                verticalDistances[child] = max(verticalDistances[currNode], secondLargestChildHeight + 1) + 1;
            } else {
                verticalDistances[child] = max(verticalDistances[currNode], largestChildHeight + 1) + 1;
            }
            calculateVerticalDistances(child, currNode);
        }
    }
}


int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1-1].push_back(v2-1);
        edges[v2-1].push_back(v1-1);
    }
    calculateHeights(0, -1);
    verticalDistances[0] = 0;
    calculateVerticalDistances(0, -1);
    for(int i = 0; i < n; i++) {
        cout << max(heights[i], verticalDistances[i]) << " ";
    }
    cout << endl;
    return 0;
}
