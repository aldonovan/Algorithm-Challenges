#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void winValues(vector<pair<int, int>> currPatches, int enemyOne, int enemyTwo, long long totalSum,
    vector<long long> &winnableValues) {
    if (currPatches.size() == 0) {
        return;
    }
    long long oneValue = currPatches[0].second;
    long long runningValue = currPatches[0].second;
    int endIndex = 0;
    for (int i = 0; i < currPatches.size(); i++) {
        while (endIndex < currPatches.size() - 1 && 
        2*currPatches[i].first - enemyOne - 1 >= currPatches[endIndex + 1].first - (enemyTwo - currPatches[endIndex + 1].first) + 1) {
            endIndex++;
            runningValue += currPatches[endIndex].second;
        }
        oneValue = max(oneValue, runningValue);
        runningValue -= currPatches[i].second;
    }
    winnableValues.push_back(oneValue);
    winnableValues.push_back(totalSum - oneValue);
}

int main() {
    int k, m, n;
    cin >> k >> m >> n;
    pair<int, int> patches[k];
    int enemies[m];
    for (int i = 0; i < k; i++) {
        int location, tastiness;
        cin >> location >> tastiness;
        patches[i] = make_pair(location, tastiness);
    } 
    for (int i = 0; i < m; i++) cin >> enemies[i];
    sort(patches, patches + k);
    sort(enemies, enemies + m);
    vector<long long> winnableValues;
    int patchIndex = 0;
    for(int i = 0; i < m; i++) {
        // Proessing enemies[i-1] and enemies[i]
        vector<pair<int, int>> currPatches;
        long long runningSum = 0;
        while (patchIndex < k && patches[patchIndex].first <= enemies[i]) {
            currPatches.push_back(patches[patchIndex]);
            runningSum += patches[patchIndex].second;
            patchIndex++;
        }
        if (i == 0) {
            winnableValues.push_back(runningSum);
        } else {
            winValues(currPatches, enemies[i - 1], enemies[i], runningSum, winnableValues);
        }
    }
    long long runningSum = 0;
    while(patchIndex < k) {
        runningSum += patches[patchIndex].second;
        patchIndex++;
    }
    winnableValues.push_back(runningSum);
    sort(winnableValues.begin(), winnableValues.end());
    long long highestWin = 0;
    for (int i = winnableValues.size() - 1; i >= max(0, (int)(winnableValues.size()) - n); i--) {
        highestWin += winnableValues[i];
    }
    cout << highestWin << endl;
    return 0;
}
