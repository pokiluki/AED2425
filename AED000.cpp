#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


int main() {
    int N, result = 0;
    std::cin >> N;
    std::vector<int> sequence(N);
    
    for (int i = 0; i < N; ++i) {
        int n = 0;
        cin >> n;
        if(n==42){
            result += 1;
        }
        }
    cout << result << endl;
    
    return 0;
}
