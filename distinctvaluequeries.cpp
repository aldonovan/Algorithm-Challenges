#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int seg[800000];
int n;

void insert(int curr, int start, int end, int index, int value) {
    if(index < start || index > end) return;
    if(start == end) {
        seg[curr] = value;
        return;
    }
    insert(2*curr + 1, start, (start + end)/2, index, value);
    insert(2*curr + 2, (start+end)/2+1, end, index, value);
    seg[curr] = seg[2*curr + 1] + seg[2*curr + 2];
}

void insert(int index, int value) {
    insert(0, 0, n-1, index, value);
}

int sum(int curr, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(start >= left && end <= right) return seg[curr];
    return sum(2*curr + 1, start, (start + end)/2, left, right) + sum(2*curr + 2, (start+end/2)+1, end, left, right);
}

int sum(int left, int right) {
    return sum(0, 0, n-1, left, right);
}

bool comp(vector<int> v1, vector<int> v2) {
    return v1[1] < v2[1];
}

int main() {
    int q;
    cin >> n >> q;
    int numbers[n];
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    vector<vector<int> > queries;
    for(int i = 0; i < q; i++) {
        int start, end;
        cin >> start >> end;
        vector<int> query;
        query.push_back(start);
        query.push_back(end);
        query.push_back(i);
        queries.push_back(query);
    }
    sort(queries.begin(), queries.end(), comp);
    unordered_map<int, int> lastAppearance;
    int currIndex = 0;
    for(int i = 0; i < n; i++) {
        insert(i, 0);
    }
    int result[q];
    for(int i = 0; i < queries.size(); i++) {
        int currEnd = queries[i][1] - 1;
        while(currIndex <= currEnd) {
            if(!(lastAppearance.find(numbers[currIndex]) == lastAppearance.end())) {
                insert(lastAppearance[numbers[currIndex]], 0);
            }
            insert(currIndex, 1);
            lastAppearance[numbers[currIndex]] = currIndex;
            currIndex++;
        }
        result[queries[i][2]] = sum(queries[i][0]-1, queries[i][1]-1);
    }
    for(int i = 0; i < q; i++) {
        cout << result[i] << endl;
    }
    return 0;
}
