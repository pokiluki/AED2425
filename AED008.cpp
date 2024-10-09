#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
using namespace std;

int maxPartitionSum(const vector<int>& v, int partitions) {
    int low = *max_element(v.begin(), v.end());
    int high = accumulate(v.begin(), v.end(), 0);
    
    auto canPartition = [&](int maxSum) {
        int currentSum = 0, requiredPartitions = 1;
        for (int num : v) {
            if (currentSum + num > maxSum) {
                currentSum = num;
                ++requiredPartitions;
                if (requiredPartitions > partitions) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    };
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (canPartition(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    return low;
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
        
        result = maxPartitionSum(sequence, query);
        cout << result << endl;
    }
    
    return 0;
}
