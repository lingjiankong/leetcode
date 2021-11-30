// ***
//
// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//
// Example 2:
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3
//
// ***

// Union-find
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        UnionFind<string> uf;

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    string curPos = to_string(i) + "," + to_string(j);
                    uf.add(curPos);
                    for (vector<int>& dir : dirs) {
                        int neighX = i + dir[0], neighY = j + dir[1];
                        if (0 <= neighX and neighX < m and 0 <= neighY and neighY < n and grid[neighX][neighY] == '1') {
                            string neighPos = to_string(neighX) + "," + to_string(neighY);
                            if (uf.has(neighPos)) {
                                uf.connect(curPos, neighPos);
                            }
                        }
                    }
                }
            }
        }

        return uf.numClusters();
    }
};


// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() or grid[0].empty()) {
            return 0;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int totalIslands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1' and not visited[i][j]) {
                    _dfs(i, j, grid, visited);
                    ++totalIslands;
                }
            }
        }

        return totalIslands;
    }

private:
    void _dfs(int x, int y, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or visited[x][y] or grid[x][y] != '1') {
            return;
        }

        visited[x][y] = true;

        for (vector<int>& dir : _dirs) {
            int neighX = x + dir[0], neighY = y + dir[1];
            _dfs(neighX, neighY, grid, visited);
        }
    }

    vector<vector<int>> _dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};


// Same idea (DFS), "visited" at different position.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() or grid[0].empty()) {
            return 0;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int totalIslands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1' and not visited[i][j]) {
                    visited[i][j] = true;
                    _dfs(i, j, grid, visited);
                    ++totalIslands;
                }
            }
        }

        return totalIslands;
    }

private:
    void _dfs(int x, int y, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        for (vector<int>& dir : _dirs) {
            int neighX = x + dir[0], neighY = y + dir[1];
            if (neighX >= 0 and neighX < grid.size() and neighY >= 0 and neighY < grid[0].size() and
                grid[neighX][neighY] == '1' and not visited[neighX][neighY]) {
                visited[neighX][neighY] = true;
                _dfs(neighX, neighY, grid, visited);
            }
        }
    }

    vector<vector<int>> _dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
