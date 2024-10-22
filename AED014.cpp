#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    int N;
    std::cin >> N;
    std::vector<int> sequence(N);
    std::vector<int> sequence2(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> sequence[i];
        std::cin >> sequence2[i];
    }

    sort(sequence.begin(), sequence.end());
    sort(sequence2.begin(), sequence2.end());

    int count = 0;
    int i = 0, j = 0, maxCount = 0;

    while (i < N && j < N) {
        if (sequence[i] <= sequence2[j]) {
            count++;
            maxCount = max(maxCount, count);
            i++;
        } else {
            count--;
            j++;
        }
    }

    count = maxCount;

    cout << count << endl;

    return 0;
}