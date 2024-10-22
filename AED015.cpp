#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

string rm_spces_nd_tolower(string str) {
    string new_str = "";
    for (long unsigned int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            new_str += tolower(str[i]);
        }
    }
    sort(new_str.begin(), new_str.end());
    return new_str;
}

int main(){

    int N;
    vector<string> words;
    set<string> anagrams;

    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string word;
        getline(cin, word);
        word = rm_spces_nd_tolower(word);
        if (find(words.begin(), words.end(), word) != words.end()) {
           anagrams.insert(word);
        }
        else {
            words.push_back(word);
        }
    }

    cout << anagrams.size() << endl;

    return 0;
}