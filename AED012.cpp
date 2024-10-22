#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

bool bigger(int & x, int & y){
    return x > y;
}

int main() {
    int N, K;
    std::cin >> N;
    cin >> K;
    std::vector<int> sequence(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> sequence[i];
    }
    
    sort(sequence.begin(), sequence.end(), bigger);

    for (int j = 0; j < K; j++){
        cout << sequence[j] << endl;
    }

    
    return 0;
}
