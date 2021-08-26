#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int maxBoxes(vector<int> boxes, vector<int> positions) {
    int mostBoxes = 0;
    vector<int> alreadyCorrect(positions.size(), 0);
    int positionIndex = positions.size() - 1;
    int boxIndex = boxes.size() - 1;
    while(positionIndex >= 0 && boxIndex >= 0) {
        if(positions[positionIndex] > boxes[boxIndex]) {
            positionIndex--;
            if(positionIndex >= 0) alreadyCorrect[positionIndex] += alreadyCorrect[positionIndex + 1];
        } else if(positions[positionIndex] < boxes[boxIndex]) {
            boxIndex--;
        } else {
            alreadyCorrect[positionIndex] += 1;
            positionIndex--;
            if(positionIndex >= 0) alreadyCorrect[positionIndex] += alreadyCorrect[positionIndex + 1];
            boxIndex--;
        }
    }

    queue<int> curr;
    boxIndex = 0;
    for(int i = 0; i < positions.size(); i++) {
        while(boxIndex < boxes.size() && boxes[boxIndex] <= positions[i]) {
            boxIndex++;
        }
        curr.push(positions[i]);
        while(!curr.empty() && curr.front() <= positions[i] - boxIndex) {
            curr.pop();
        }
        int numBoxes = curr.size();
        if(i < positions.size() - 1) numBoxes += alreadyCorrect[i+1];
        mostBoxes = max(mostBoxes, numBoxes);
    }

    return mostBoxes;
}


int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        vector<int> leftBoxes;
        vector<int> rightBoxes;
        vector<int> leftPositions;
        vector<int> rightPositions;
        for(int i = 0; i < n; i++) {
            int box; 
            cin >> box;
            if(box < 0) {
                leftBoxes.push_back(-1*box);
            } else {
                rightBoxes.push_back(box);
            }
        }
        for(int i = 0; i < m; i++) {
            int position; 
            cin >> position;
            if(position < 0) {
                leftPositions.push_back(-1*position);
            } else {
                rightPositions.push_back(position);
            }
        }
        reverse(leftBoxes.begin(), leftBoxes.end());
        reverse(leftPositions.begin(), leftPositions.end());
        cout << maxBoxes(leftBoxes, leftPositions) + maxBoxes(rightBoxes, rightPositions) << endl;
    }
    return 0;
}
