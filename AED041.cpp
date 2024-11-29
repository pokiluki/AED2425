#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int A, B;

    multiset<int> mA, mB;

    cin >> A;
    for(int i = 0; i < A; i++){
        int x;
        cin >> x;
        mA.insert(x);
    }

    cin >> B;
    for(int i = 0; i < B; i++){
        int x;
        cin >> x;
        mB.insert(x);
    }

    while (!mA.empty() && !mB.empty())
    {
        auto it = mA.end();
        auto it2 = mB.end();
        it--;
        it2--;

        int a = *it;
        int b = *it2;

        mA.erase(it);
        mB.erase(it2);

        if(a > b){
            int na = a - b;
            mA.insert(na);
        }

        if(b > a){
            int nb = b - a;
            mB.insert(nb);
        }
    
    
    }

    if(mA.size() == 0 && mB.size() == 0){
        cout << "Tie" << endl;
        cout << "0" << endl;
    } else if(mA.size() == 0){
        cout << "Bob wins" << endl;
        cout << mB.size() << endl;
    } else {
        cout << "Alice wins" << endl;
        cout << mA.size() << endl;
    }

    return 0;

}