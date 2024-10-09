#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N;
    std::cin >> N;
    std::vector<int> sequence(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> sequence[i];
    }
    int max_sum = sequence[0];
    int current_sum = sequence[0];

    for (int i = 1; i < N; ++i) {
        current_sum = std::max(sequence[i], current_sum + sequence[i]);
        max_sum = std::max(max_sum, current_sum);
    }

    std::cout << max_sum << std::endl;
    
    return 0;
}