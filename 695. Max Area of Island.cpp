// ***
//
// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected
// 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
//
// Example 1:
//
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
//
// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
//
// Example 2:
//
// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
// Note: The length of each dimension in the given grid does not exceed 50.
//
// ***

// DFS
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int maxArea = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    _dfs(i, j, area, grid, visited);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

private:
    vector<vector<int>> _dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void _dfs(int x, int y, int& area, const vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || visited[x][y] || grid[x][y] != 1) {
            return;
        }

        visited[x][y] = true;
        ++area;

        for (auto& dir : _dirs) {
            int newX = x + dir[0], newY = y + dir[1];
            _dfs(newX, newY, area, grid, visited);
        }
    }
};

// Union-find
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        UnionFind<string> uf;

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    string curPos = to_string(i) + "," + to_string(j);
                    uf.add(curPos);
                    for (vector<int>& dir : dirs) {
                        int neighX = i + dir[0], neighY = j + dir[1];
                        if (0 <= neighX and neighX < m and 0 <= neighY and neighY < n and grid[neighX][neighY] == 1) {
                            string neighPos = to_string(neighX) + "," + to_string(neighY);
                            if (uf.has(neighPos)) {
                                uf.connect(curPos, neighPos);
                            }
                        }
                    }
                }
            }
        }

        int maxArea = 0;
        for (auto& e : uf.size()) {
            maxArea = max(maxArea, e.second);
        }
        return maxArea;
    }
};

