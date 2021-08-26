#include <iostream>
#include <queue>
#include <vector> 
using namespace std;

int gcd(int x, int y) {
    if(y < x) return gcd(y, x);
    if(y % x == 0) return x;
    return gcd(y % x, x);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int numSongs;
        cin >> numSongs;
        int songs[numSongs];
        for(int j = 0; j < numSongs; j++) {
            cin >> songs[j];
        }
        vector<int> deletedSongs;
        vector<vector<int> > components;
        int compStart = 0;
        for(int j = 1; j < numSongs; j++) {
            int currGcd = gcd(songs[j], songs[j-1]);
            if(currGcd == 1) {
                deletedSongs.push_back(j + 1);
                vector<int> lastComponent;
                lastComponent.push_back(compStart);
                lastComponent.push_back(j - 1);
                compStart = j + 1;
                components.push_back(lastComponent);
            }
        }
        if(compStart < numSongs) {
            vector<int> lastComponent;
            lastComponent.push_back(compStart);
            lastComponent.push_back(numSongs - 1);
            components.push_back(lastComponent);
        }
        // queue<int> songCandidates;
        // vector<int> deletedSongs;
        // vector<bool> deleted(numSongs, false);
        // for(int j = 1; j < numSongs; j++) {
        //     songCandidates.push(j);
        // }
        // songCandidates.push(0);
        // int iteration = 1;
        // while(!songCandidates.empty()) {
        //     int s = songCandidates.size();
        //     for(int i = 0; i < s; i++) {
        //         int currIndex = songCandidates.front();
        //         songCandidates.pop();
        //         int lastIndex = currIndex - iteration;
        //         if(lastIndex < 0) lastIndex += numSongs;
        //         if(!deleted[lastIndex] && gcd(songs[currIndex], songs[lastIndex]) == 1) {
        //             deleted[currIndex] = true;
        //             deletedSongs.push_back(currIndex + 1);
        //             int nextSong = (currIndex + 1) % numSongs;
        //             if(!deleted[nextSong]) {
        //                 songCandidates.push(nextSong);
        //             }
        //         }
        //     }
        //     iteration++;
        // }
        // cout << deletedSongs.size();
        // for(int i = 0; i < deletedSongs.size(); i++) {
        //     cout << " " << deletedSongs[i];
        // }
        // cout << endl;
    } 
    return 0;
    
}
