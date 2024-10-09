#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;



int search(const vector<int> & v, int key) {

  int low = 0, high = (int)v.size() - 1;
while (low <= high) {
  int middle = low + (high - low) / 2;
  if (key < v[middle])      high = middle - 1;
  else if (key > v[middle]) low = middle + 1;
  else return middle; // found key
}
return -1; // not found
}

int main() {
    int N, Q;
    std::cin >> N;
    std::vector<int> sequence(N);
    
    for (int i = 0; i < N; ++i) {
        std::cin >> sequence[i];
    }
    
    std::cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int query, result;
        std::cin >> query;
        
        result = search(sequence, query);
        
        cout << result << endl;
    }
    
    return 0;
}
