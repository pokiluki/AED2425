#include <iostream>
#include <queue>
#include <string>

struct Process {
    std::string name;
    int remainingTime;
    int startTime;
};

int main() {
    int T, N;
    std::cin >> T >> N;

    std::queue<Process> processQueue;
    for (int i = 0; i < N; ++i) {
        Process p;
        std::cin >> p.name >> p.remainingTime;
        p.startTime = 0;
        processQueue.push(p);
    }

    int currentTime = 0;
    int iterations = 0;

    while (!processQueue.empty()) {
        Process currentProcess = processQueue.front();
        processQueue.pop();
        iterations++;

        if (currentProcess.remainingTime <= T) {
            currentTime += currentProcess.remainingTime;
            std::cout << currentProcess.name << " " << currentTime << " " << iterations << std::endl;
        } else {
            currentTime += T;
            currentProcess.remainingTime -= T;
            currentProcess.startTime = currentTime;
            processQueue.push(currentProcess);
        }
    }

    return 0;
}