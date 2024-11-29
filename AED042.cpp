#include <iostream>
#include <map>

using namespace std;

int main(){
    int A;

    map<int, int> mA;

    cin >> A;

    for(int i = 0; i < A-1; i++){
        int x;
        cin >> x;
        if (mA.find(x) == mA.end())
        {
            mA[x] = i+1;
            cout << "-1 ";
        } 
        
        else
        {
            cout << mA[x] << " ";
            mA[x] = i+1;
        }   
    }

    int x;
    cin >> x;
    if (mA.find(x) == mA.end())
    {
        cout << "-1" << endl;
    } 
    
    else
    {
        cout << mA[x] << endl;
    }

    return 0;

}