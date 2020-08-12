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
//
// The whole idea is Breadth First Search.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minDistance(const pair<int, int>& start, const pair<int, int>& goal, const vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> distance(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n));

    // Applying BFS on matrix cells starting from start
    queue<pair<int, int>> cellQueue;

    cellQueue.push(start);
    distance[start.first][start.second] = 0;
    visited[start.first][start.second] = true;

    while (!cellQueue.empty()) {
        pair<int, int> cell = cellQueue.front();
        cellQueue.pop();
        int x = cell.first, y = cell.second;

        if (pair<int, int>(x, y) == goal) {
            return distance[x][y];
        }

        // Moving up
        if (x - 1 >= 0 && grid[x - 1][y] != 'x' && !visited[x - 1][y]) {
            cellQueue.push({x - 1, y});
            distance[x - 1][y] = distance[x][y] + 1;
            visited[x - 1][y] = true;
        }

        // Moving down
        if (x + 1 < m && grid[x + 1][y] != 'x' && !visited[x + 1][y]) {
            cellQueue.push({x + 1, y});
            distance[x + 1][y] = distance[x][y] + 1;
            visited[x + 1][y] = true;
        }

        // Moving left
        if (y - 1 >= 0 && grid[x][y - 1] != 'x' && !visited[x][y - 1]) {
            cellQueue.push({x, y - 1});
            distance[x][y - 1] = distance[x][y] + 1;
            visited[x][y - 1] = true;
        }

        // Moving right
        if (y + 1 < n && grid[x][y + 1] != 'x' && !visited[x][y + 1]) {
            cellQueue.push({x, y + 1});
            distance[x][y + 1] = distance[x][y] + 1;
            visited[x][y + 1] = true;
        }
    }

    return -1;
}

int main() {
    vector<vector<char>> grid = {
        {'x', 'o', 'x', 'o'}, {'o', 'x', 'o', 'o'}, {'x', 'o', 'o', 'o'}, {'o', 'o', 'o', 'o'}};

    pair<int, int> start = {0, 3};
    pair<int, int> goal = {3, 0};

    cout << minDistance(start, goal, grid) << endl;

    return 0;
}
