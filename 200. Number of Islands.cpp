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

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int totalIslands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    _dfs(i, j, grid, visited);
                    ++totalIslands;
                }
            }
        }

        return totalIslands;
    }

private:
    void _dfs(int x, int y, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || visited[x][y] || grid[x][y] != '1') {
            return;
        }

        visited[x][y] = true;

        for (auto direction : _directions) {
            int newX = x + direction[0], newY = y + direction[1];
            _dfs(newX, newY, grid, visited);
        }
    }

    vector<vector<int>> _directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
