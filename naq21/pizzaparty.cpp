#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
    int c;
    cin >> c;
    vector<vector<string>> words;
    unordered_set<string> requiredToppings;
    for (int i = 0; i <= c; i++) {
        string t;
        getline(cin, t);
        istringstream iss(t);
        string currWord;
        int numWords = 0;
        vector<string> currWords;
        bool foundFront = false;
        while (iss >> currWord) {
            if (currWord != "and" && currWord != "then" && currWord != "if") {
                currWords.push_back(currWord);
            }
            if (currWord == "and" && !foundFront) {
                currWords.insert(currWords.begin(), "and");
                foundFront = true;
            }
            if (currWord == "or" && !foundFront) {
                currWords.insert(currWords.begin(), "or");
                foundFront = true;
            }
            numWords++;
        }
        if (numWords == 1) {
            requiredToppings.insert(currWords[0]);
        } else {
            if (!foundFront) {
                currWords.insert(currWords.begin(), "or");
            }
            words.push_back(currWords);
        }
    }
    int numChanges = 1;
    while(numChanges > 0) {
        numChanges = 0;
        for (int index = 1; index < words.size(); index++) {
            vector<string> currPref = words[index];
            if (currPref[0] == "and") {
                for (int wordIndex = 1; wordIndex < currPref.size(); wordIndex++) {
                    if (wordIndex == currPref.size() - 1) {
                        requiredToppings.insert(currPref[wordIndex]);
                        numChanges++;
                        words.erase(words.begin() + index);
                        index--;
                    } else if (requiredToppings.find(currPref[wordIndex]) == requiredToppings.end()) {
                        break;
                    }
                }
            } else {
                bool containsOne = false;
                for (int wordIndex = 1; wordIndex < currPref.size(); wordIndex++) {
                    if (wordIndex == currPref.size() - 1 && containsOne) {
                        requiredToppings.insert(currPref[wordIndex]);
                        numChanges++;
                        words.erase(words.begin() + index);
                        index--;
                    } else if (requiredToppings.find(currPref[wordIndex]) != requiredToppings.end()) {
                        containsOne = true;
                        wordIndex = currPref.size() - 2;
                    }
                }
            }
        }        
    }
    cout << requiredToppings.size() << endl;
    return 0;
}
