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
#include <set>
#include <vector>

using namespace std;

// 1. Obtain the shortest distance from start to goal
int minDistance(const pair<int, int>& start, const pair<int, int>& goal, const vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));

    // Applying BFS on matrix cells starting from start
    queue<pair<int, int>> q;

    q.push(start);
    visited[start.first][start.second] = true;
    int distance = 0;

    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            pair<int, int> cell = q.front();
            q.pop();
            int x = cell.first, y = cell.second;

            if (pair<int, int>(x, y) == goal) {
                return distance;
            }

            if (grid[x][y] == 'x') {
                continue;
            }

            // Moving up
            if (x - 1 >= 0 && !visited[x - 1][y]) {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
            }

            // Moving down
            if (x + 1 < m && !visited[x + 1][y]) {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
            }

            // Moving left
            if (y - 1 >= 0 && !visited[x][y - 1]) {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }

            // Moving right
            if (y + 1 < n && !visited[x][y + 1]) {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }
        }

        ++distance;
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

// 2. This is also works. You can check whether grid[x][y] == "x" while checking visited.
// Note that, this will not be able to handle the case when the starting location is already a "x"
int minDistance(const pair<int, int>& start, const pair<int, int>& goal, const vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<bool>> visited(m, vector<bool>(n));

    // Applying BFS on matrix cells starting from start
    queue<pair<int, int>> q;

    q.push(start);
    visited[start.first][start.second] = true;
    int distance = 0;

    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            pair<int, int> cell = q.front();
            q.pop();
            int x = cell.first, y = cell.second;

            if (pair<int, int>(x, y) == goal) {
                return distance;
            }

            // Moving up
            if (x - 1 >= 0 && grid[x - 1][y] != 'x' && !visited[x - 1][y]) {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
            }

            // Moving down
            if (x + 1 < m && grid[x + 1][y] != 'x' && !visited[x + 1][y]) {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
            }

            // Moving left
            if (y - 1 >= 0 && grid[x][y - 1] != 'x' && !visited[x][y - 1]) {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }

            // Moving right
            if (y + 1 < n && grid[x][y + 1] != 'x' && !visited[x][y + 1]) {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }
        }

        ++distance;
    }

    return -1;
}

// 3. Bidirectional BFS. Comapre with 752. Open the Lock
struct Comparator {
    template <typename T>
    bool operator()(const T& l, const T& r) const {
        if (l.first == r.first) {
            return l.second < r.second;
        }
        return l.first < r.first;
    }
};

int minDistance(const pair<int, int>& start, const pair<int, int>& goal, const vector<vector<char>>& grid) {
    set<pair<int, int>, Comparator> q1;
    q1.insert(start);

    set<pair<int, int>, Comparator> q2;
    q2.insert(goal);

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));

    int distance = 0;

    while (not q1.empty() and not q2.empty()) {
        if (q1.size() > q2.size()) {
            swap(q1, q2);
        }

        set<pair<int, int>, Comparator> temp;

        for (pair<int, int> cell : q1) {
            int x = cell.first, y = cell.second;

            visited[x][y] = true;

            if (grid[x][y] == 'x') {
                continue;
            }

            if (q2.count({x, y})) {
                return distance;
            }

            // Moving up
            if (x - 1 >= 0 && !visited[x - 1][y]) {
                temp.insert({x - 1, y});
            }

            // Moving down
            if (x + 1 < m && !visited[x + 1][y]) {
                temp.insert({x + 1, y});
            }

            // Moving left
            if (y - 1 >= 0 && !visited[x][y - 1]) {
                temp.insert({x, y - 1});
            }

            // Moving right
            if (y + 1 < n && !visited[x][y + 1]) {
                temp.insert({x, y + 1});
            }
        }
        ++distance;
        q1 = temp;
    }

    return -1;
}

// 4. Obtain the shortest distance from start to every (x, y).
int minDistance(const pair<int, int>& start, const pair<int, int>& goal, const vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> distance(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n));

    // Applying BFS on matrix cells starting from start
    queue<pair<int, int>> q;

    q.push(start);
    distance[start.first][start.second] = 0;
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        int x = cell.first, y = cell.second;

        if (pair<int, int>(x, y) == goal) {
            return distance[x][y];
        }

        // Moving up
        if (x - 1 >= 0 && grid[x - 1][y] != 'x' && !visited[x - 1][y]) {
            q.push({x - 1, y});
            distance[x - 1][y] = distance[x][y] + 1;
            visited[x - 1][y] = true;
        }

        // Moving down
        if (x + 1 < m && grid[x + 1][y] != 'x' && !visited[x + 1][y]) {
            q.push({x + 1, y});
            distance[x + 1][y] = distance[x][y] + 1;
            visited[x + 1][y] = true;
        }

        // Moving left
        if (y - 1 >= 0 && grid[x][y - 1] != 'x' && !visited[x][y - 1]) {
            q.push({x, y - 1});
            distance[x][y - 1] = distance[x][y] + 1;
            visited[x][y - 1] = true;
        }

        // Moving right
        if (y + 1 < n && grid[x][y + 1] != 'x' && !visited[x][y + 1]) {
            q.push({x, y + 1});
            distance[x][y + 1] = distance[x][y] + 1;
            visited[x][y + 1] = true;
        }
    }

    return -1;
}

