#include <iostream>
#include <string_view>
#include <array>
#include <fstream>
#include <string> 
#include <vector>

using namespace std;

int main() {
    ifstream istrm("/Users/alexdonovan/Desktop/Competitive Programming/Algorithm Code/project_euler/p022_names.txt");
    string s;
    istrm >> s;
    vector<string> names;
    std::string_view names_view = s;
    while (true) {
        int index = names_view.find(',');
        if (index < 0) {
            names.push_back(string(names_view.substr(1, names_view.size() - 2)));
            break;
        }
        names.push_back(string(names_view.substr(1, index - 2)));
        names_view = names_view.substr(index + 1);
    }
    sort(names.begin(), names.end());
    std::array<int, 26> letter_scores;
    for (int i = 0; i < 26; ++i) {
        letter_scores[i] = i + 1;
    }
    long long total_score = 0;
    for (int i = 0; i < names.size(); ++i) {
        int current_word_score = 0;
        for (int c : names[i]) {
            current_word_score += letter_scores[c-'A'];
        }
        total_score += current_word_score * (i+1);
    }
    cout << total_score << '\n';
}
