// ***
//
// Given a matrix of size m by n, find the shortest path from a source cell to a goal cell.
// You can only move up, down, left and right.
//
// If there's no path between start and goal, return -1.
//
// 's' represents source
// 'd' represents goal
// 'o' represents cell you can travel
// 'x' represents obstacles
//
// ***
//
// The same logic as N1. Shortest Distance Between Two Cells in a Matirx.
// Depending whether you want to return the shortest distance or the shortest path, you should either:
//
// 1. Maintain a vector<vector<int>> distance, which stores the distance from goal to start for every (x, y)
// if you want the minimum distance between start and goal, OR
//
// 2. Maintain a vector<vector<pair<int, int>>> from, which from[x][y] stores which cell you came from to reach (x, y)
// You later use this matrix to reconstruct the path. If you store vector<vector<pair<int, int>>> from,
// then there's no need for distance matrix, because distance can be implicitly computed from the path.

#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int>> shortestPath(const pair<int, int>& start, const pair<int, int>& goal,
                                    const vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<pair<int, int>>> from(m, vector<pair<int, int>>(n, {INT_MAX, INT_MAX}));
    vector<vector<bool>> visited(m, vector<bool>(n));

    // Applying BFS on matrix cells starting from start
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while (not q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        int x = cell.first, y = cell.second;

        // Found the goal.
        if (pair<int, int>(x, y) == goal) {
            break;
        }

        for (vector<int>& dir : dirs) {
            int neighX = x + dir[0], neighY = y + dir[1];
            if (neighX >= 0 and neighX < m and neighY >= 0 and neighY < n and grid[neighX][neighY] != 'x' and
                not visited[neighX][neighY]) {
                q.push({neighX, neighY});
                from[neighX][neighY] = {x, y};
                visited[neighX][neighY] = true;
            }
        }
    }

    // Reconstruct path (from goal to start)
    vector<pair<int, int>> toReturn;
    pair<int, int> cell = goal;
    while (cell != pair<int, int>(INT_MAX, INT_MAX)) {
        toReturn.push_back({cell.first, cell.second});
        cell = from[cell.first][cell.second];
    }

    // Reverse the path (so it is from start to goal)
    reverse(toReturn.begin(), toReturn.end());
    cout << "Shortest path to goal is: " << endl;
    for (auto& cell : toReturn) {
        cout << "(" << cell.first << ", " << cell.second << ") " << endl;
    }
    cout << "Distance to goal is: " << toReturn.size() - 1 << endl;

    return toReturn;
}

int main() {
    vector<vector<char>> grid = {
        {'x', 'o', 'x', 'o'}, {'o', 'x', 'o', 'o'}, {'x', 'o', 'o', 'o'}, {'o', 'o', 'o', 'x'}};

    pair<int, int> start = {0, 3};
    pair<int, int> goal = {3, 0};

    vector<pair<int, int>> path = shortestPath(start, goal, grid);

    return 0;
}
