#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <functional>
#include <unordered_map>
#include <string>

using namespace std;


int main(){
    int K;
    int max = 0;
    int n_max = 0;
    string s;
    unordered_map<string, int> m;

    cin >> K;

    cin.ignore();
    getline(cin, s);

    for (long unsigned int i = 0; i < s.size() - K +1; i++){
        m[s.substr(i, K)]++;
    }

    for (auto it = m.begin(); it != m.end(); it++){
        if (it->second > max){
            max = it->second;
        }
    }

    cout << max << endl;

    for (auto it = m.begin(); it != m.end(); it++){
        if(it->second == max){
            n_max++;
        }
    }

    if(n_max>1){
        cout << n_max << endl;
    }

    if(n_max == 1){
        for (auto it = m.begin(); it != m.end(); it++){
            if(it->second == max){
                cout << it->first << endl;
            }
        }
    }
    
    return 0;
}