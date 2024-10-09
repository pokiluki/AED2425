#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


int main() {
    int N, Q;
    std::cin >> N;
    std::vector<int> sequence(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> sequence[i];
    }
    
    std::cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int B, E, result;
        std::cin >> B >> E;
        
        result = upper_bound(sequence.begin(), sequence.end(), E) - lower_bound(sequence.begin(), sequence.end(), B);
        cout << result << endl;
    }
    
    return 0;
}
