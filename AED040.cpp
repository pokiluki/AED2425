#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int C, B, Ci, Bi;
    set<int> s;
    set<int> ns;

    cin >> C;

    for (int i = 0; i < C; i++){
        cin >> Ci;
        s.insert(Ci);
    }

    cin >> B;

    for (int i = 0; i < B; i++){
        cin >> Bi;
        if (s.find(Bi) == s.end()){
            ns.insert(Bi);
            s.insert(Bi);
        }
    }

    cout << ns.size() << endl;
    
    if(ns.size() == 0){
        return 0;
    }
    for (auto i : ns){
        if (i != *ns.rbegin()) {
            cout << i << " ";
        } else {
            cout << i;
        }
    }
    cout << endl;

    return 0;
}