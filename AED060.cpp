#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Position {
    int row, col, dist;
};

bool isValid(int row, int col, int R, int C, vector<vector<char>>& maze, vector<vector<bool>>& visited) {
    return (row >= 0 && row < R && col >= 0 && col < C && maze[row][col] != '#' && !visited[row][col]);
}

int bfs(vector<vector<char>>& maze, int R, int C, Position start, Position end) {
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    queue<Position> q;
    q.push(start);
    visited[start.row][start.col] = true;

    int rowDir[] = {-1, 1, 0, 0};
    int colDir[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Position curr = q.front();
        q.pop();

        if (curr.row == end.row && curr.col == end.col) {
            return curr.dist;
        }

        for (int i = 0; i < 4; ++i) {
            int newRow = curr.row + rowDir[i];
            int newCol = curr.col + colDir[i];

            if (isValid(newRow, newCol, R, C, maze, visited)) {
                visited[newRow][newCol] = true;
                q.push({newRow, newCol, curr.dist + 1});
            }
        }
    }

    return -1;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int R, C;
        cin >> R >> C;

        vector<vector<char>> maze(R, vector<char>(C));
        Position start, end;

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> maze[i][j];
                if (maze[i][j] == 'P') {
                    start = {i, j, 0};
                } else if (maze[i][j] == 'T') {
                    end = {i, j, 0};
                }
            }
        }

        cout << bfs(maze, R, C, start, end) << endl;
    }

    return 0;
}