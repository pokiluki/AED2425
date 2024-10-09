#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

bool is_Prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int main() {
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N; ++i) {
        int n;
        std::cin >> n;
        
        if (is_Prime(n)) {
            cout << n << " is prime" << endl;
        } else {
            cout << n << " is composite" << endl;
        }
    }
    
    return 0;
}