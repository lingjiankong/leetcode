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
#include <unordered_set>
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

// 2. Bidirectional BFS. See 752. Open the Lock for detailed explanation.
int minDistance(const vector<int>& start, const vector<int>& goal, const vector<vector<char>>& grid) {
    unordered_set<vector<int>> q1;
    q1.insert(start);

    unordered_set<vector<int>> q2;
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

        unordered_set<vector<int>> temp;

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

// For interviewing others:

// Template:

// ***
//
// Given a 2D grid of size m by n, find the shortest path from upper left cell to every other cell.
// You can only move up, down, left and right. If a cell is unreachable, return INT_MAX.
//
// 0 represents free cell;
// 1 represents obstacle that you cannot cross;
//
// Example:
// Input:
// {
//     {0, 1, 0, 0},
//     {0, 0, 1, 0},
//     {1, 0, 0, 0},
//     {0, 1, 0, 0}
// };
//
// Output:
// {
//     {0, X, 8, 7},
//     {1, 2, X, 6},
//     {X, 3, 4, 5},
//     {X, X, 5, 6}
// }
// (where X represents unreachable cell (you can use INT_MAX))
//
// ***

#include <vector>
#include <iostream>

std::vector<std::vector<int>> shortestPathFromUpperLeftCellToEveryCell(const std::vector<std::vector<int>>& grid) {
    // You code goes here.
}

// To test your code.
int main() {
    std::vector<std::vector<int>> grid = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 1, 0, 0}
    };

    const std::vector<std::vector<int>> min_distance = shortestPathFromUpperLeftCellToEveryCell(grid);

    for (int i = 0; i < min_distance.size(); ++i) {
      for (int j = 0; j < min_distance[0].size(); ++j) {
        std::cout << min_distance[i][j] << ", ";
      }
      std::cout << std::endl;
    }

    return 0;
}

// Bonus questions:
// (You do not need to write any code for the bonus questions. Verbally communicate your thought process is sufficient)
// 1. If your task is to find the shortest distance from upper left cell to lower right cell only,
//    (no need to calculate the shortest distance to other cells)
//    how would you change your appraoch? How can you speed it up?
// 2. What method would you use to calculate all UNIQUE PATHS from upper left cell to lower right cell?
// 3. If there's different costs associated with traveling from one cell to another,
//    (i.e., the distance between horizontally and vertically adjacent cells is no longer 1,
//     but can be any positive integer), how would you approach this problem?

// Solution:

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

vector<vector<int>> shortestPathFromUpperLeftCellToEveryCell(const vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> start = {0, 0};

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
            if (neighX >= 0 and neighX < m and neighY >= 0 and neighY < n and grid[neighX][neighY] != 1 and
                not visited[neighX][neighY]) {
                q.push({neighX, neighY});
                distance[neighX][neighY] = distance[x][y] + 1;
                visited[neighX][neighY] = true;
            }
        }
    }

    return distance;
}

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 0},
        {0, 1, 0, 0}
    };

    const std::vector<std::vector<int>> min_distance = shortestPathFromUpperLeftCellToEveryCell(grid);

    for (int i = 0; i < min_distance.size(); ++i) {
      for (int j = 0; j < min_distance[0].size(); ++j) {
        std::cout << min_distance[i][j] << ", ";
      }
      std::cout << std::endl;
    }

    return 0;
}
