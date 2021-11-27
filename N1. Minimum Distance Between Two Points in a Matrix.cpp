// ***
//
// Given a matrix of size m by n, find the shortest distance from a start cell to a goal cell.
// You can only move up, down, left and right.
//
// If there's no path between start and goal, return -1.
//
// 's' represents start
// 'd' represents goal
// 'o' represents cell you can travel
// 'x' represents obstacles
//
// ***

#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// 1. Obtain the shortest distance from start to goal
int minDistance(const vector<int>& start, const vector<int>& goal, const vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));

    queue<vector<int>> q;

    q.push(start);
    visited[start[0]][start[1]] = true;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int distance = 0;

    while (not q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            vector<int> cell = q.front();
            q.pop();
            int x = cell[0], y = cell[1];

            if (cell == goal) {
                return distance;
            }

            for (vector<int>& dir : dirs) {
                int neighX = x + dir[0], neighY = y + dir[1];
                if (neighX >= 0 and neighX < m and neighY >= 0 and neighY < n and grid[x][y] != 'x' and
                    not visited[neighX][neighY]) {
                    q.push({neighX, neighY});
                    visited[neighX][neighY] = true;
                }
            }
        }
        ++distance;
    }

    return -1;
}

// Same code. Use "continue".
int minDistance(const vector<int>& start, const vector<int>& goal, const vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));

    queue<vector<int>> q;

    q.push(start);
    visited[start[0]][start[1]] = true;
    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int distance = 0;

    while (not q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            vector<int> cell = q.front();
            q.pop();
            int x = cell[0], y = cell[1];

            if (cell == goal) {
                return distance;
            }

            for (vector<int>& dir : dirs) {
                int neighX = x + dir[0], neighY = y + dir[1];
                if (neighX < 0 or neighX >= m or neighY < 0 or neighY >= n) {
                    continue;
                }
                if (grid[x][y] == 'x') {
                    continue;
                }
                if (visited[neighX][neighY]) {
                    continue;
                }

                q.push({neighX, neighY});
                visited[neighX][neighY] = true;
            }
        }
        ++distance;
    }

    return -1;
}

int main() {
    vector<vector<char>> grid = {
        {'x', 'o', 'x', 'o'}, {'o', 'x', 'o', 'o'}, {'x', 'o', 'o', 'o'}, {'o', 'o', 'o', 'o'}};

    vector<int> start = {0, 3};
    vector<int> goal = {3, 0};

    cout << minDistance(start, goal, grid) << endl;

    return 0;
}

// 2. Bidirectional BFS. Comapre with 752. Open the Lock
int minDistance(const vector<int>& start, const vector<int>& goal, const vector<vector<char>>& grid) {
    set<vector<int>> q1;
    q1.insert(start);

    set<vector<int>> q2;
    q2.insert(goal);

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));

    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int distance = 0;

    while (not q1.empty() and not q2.empty()) {
        if (q1.size() > q2.size()) {
            swap(q1, q2);
        }

        set<vector<int>> temp;

        for (vector<int>& cell : q1) {
            if (q2.count(cell)) {
                return distance;
            }

            int x = cell[0], y = cell[1];
            if (grid[x][y] == 'x') {
                continue;
            }

            visited[x][y] = true;

            for (vector<int>& dir : dirs) {
                int neighX = x + dir[0], neighY = y + dir[1];
                if (neighX >= 0 and neighX < m and neighY >= 0 and neighY < n and not visited[neighX][neighY]) {
                    temp.insert({neighX, neighY});
                }
            }
        }
        ++distance;
        q1 = temp;
    }

    return -1;
}

// 3. Obtain the shortest distance from start to every (x, y).
void minDistance(const vector<int>& start, const vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    queue<vector<int>> q;
    q.push(start);

    vector<vector<bool>> visited(m, vector<bool>(n));
    visited[start[0]][start[1]] = true;

    vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
    distance[start[0]][start[1]] = 0;

    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while (not q.empty()) {
        vector<int> cell = q.front();
        q.pop();
        int x = cell[0], y = cell[1];

        for (vector<int>& dir : dirs) {
            int neighX = x + dir[0], neighY = y + dir[1];
            if (neighX >= 0 and neighX < m and neighY >= 0 and neighY < n and grid[neighX][neighY] != 'x' and
                not visited[neighX][neighY]) {
                q.push({neighX, neighY});
                distance[neighX][neighY] = distance[x][y] + 1;
                visited[neighX][neighY] = true;
            }
        }
    }
}
