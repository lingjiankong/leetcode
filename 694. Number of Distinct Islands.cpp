// ***
//
// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected
// 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//
// Count the number of distinct islands. An island is considered to be the same as another if and only if one island can
// be translated (and not rotated or reflected) to equal the other.
//
// Example 1:
// 11000
// 11000
// 00011
// 00011
// Given the above grid map, return 1.
//
// Example 2:
// 11011
// 10000
// 00001
// 11011
// Given the above grid map, return 3.
// Notice that:
// 11
// 1
// and
//  1
// 11
// are considered different island shapes, because we do not consider reflection / rotation.
// Note: The length of each dimension in the given grid does not exceed 50.
//
// ***
//
// During dfs of each island, maintain a string of the coordinates and push_back every (x - x0, y - y0) to it,
// where x0, y0 is the initial position when dfs starts (for all islands that are the same, dfs will start at the same
// relative position). This offset i.e. (x - x0, y - y0) is needed so all islands with same shape will have the same
// string of coordinates. Finally, insert the string of coordinates to an unordered_set and its size is the number of
// distinct islands.

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        unordered_set<string> islandHash;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 and !visited[i][j]) {
                    string current;

                    _dfs(i, j, i, j, current, grid, visited);

                    islandHash.insert(current);
                }
            }
        }

        return islandHash.size();
    }

private:
    void _dfs(int x0, int y0, int x, int y, string& current, const vector<vector<int>>& grid,
              vector<vector<bool>>& visited) {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || visited[x][y] || grid[x][y] != 1) {
            return;
        }

        visited[x][y] = true;
        current += " " + to_string(x - x0) + " " + to_string(y - y0);

        for (vector<int>& dir : _dirs) {
            int newX = x + dir[0], newY = y + dir[1];
            _dfs(x0, y0, newX, newY, current, grid, visited);
        }
    }

    vector<vector<int>> _dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
