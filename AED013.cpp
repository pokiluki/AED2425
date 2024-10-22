#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef struct {
  int bits;
  int num;
} Number;

int countBits(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

bool compareNumbers(const Number & x1, const Number & x2){
    if (x1.bits > x2.bits) return true;
    if (x1.bits < x2.bits) return false;
    
    return x1.num < x2.num;
}



int main() {
    int N;
    std::cin >> N;
    std::vector<Number> sequence(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> sequence[i].num;
    }

    for (int i = 0; i < N; ++i) {
        sequence[i].bits = countBits(sequence[i].num);
    }

    sort(sequence.begin(), sequence.end(), compareNumbers);

    for (int i = 0; i < N; i++){
        cout << sequence[i].num << endl;
    }

    return 0;
}