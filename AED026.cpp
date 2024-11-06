#include <list>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){

    string phrase, word;
    int k = 0;

    getline(cin, phrase);
    istringstream iss(phrase);
    while(iss >> word){
        k++;
    }
    int n;
    cin >> n;
    cin.ignore();
    list<string> names;
    for (int i = 0; i < n; i++) {
        string name;
        getline(cin, name);
        names.push_back(name);
    }

    auto it = names.begin();
    
    while (names.size() > 1)
    {
        for (int i = 1; i < k; i++) {
            it++;
            if (it == names.end()) {
                it = names.begin();
            }
        }
        
        cout << *it << endl;
        it = names.erase(it);
        
        if (it == names.end()) {
            it = names.begin();
        }
    }
    cout << *it << endl;
    

    return 0;
}