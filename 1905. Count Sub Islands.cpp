// ***
//
// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's
// (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells
// outside of the grid are considered water cells.
//
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up
// this island in grid2.
//
// Return the number of islands in grid2 that are considered sub-islands.
//
//
//
// Example 1:
//
//
// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 =
// [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]] Output: 3 Explanation: In the picture above, the grid
// on the left is grid1 and the grid on the right is grid2. The 1s colored red in grid2 are those considered to be part
// of a sub-island. There are three sub-islands. Example 2:
//
//
// Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 =
// [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]] Output: 2 Explanation: In the picture above, the grid
// on the left is grid1 and the grid on the right is grid2. The 1s colored red in grid2 are those considered to be part
// of a sub-island. There are two sub-islands.
//
//
// Constraints:
//
// m == grid1.length == grid2.length
// n == grid1[i].length == grid2[i].length
// 1 <= m, n <= 500
// grid1[i][j] and grid2[i][j] are either 0 or 1.
//
// ***

// Count the number of islands in grid2. While counting islands, see if grid1 is 1 for every cell for that island in
// grid2. If so, we found a subisland.
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;

        int m = grid2.size(), n = grid2[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1 and not visited[i][j]) {
                    bool isSubIsland = true;
                    _dfs(i, j, isSubIsland, visited, grid1, grid2);

                    if (isSubIsland) {
                        ++count;
                    }
                }
            }
        }

        return count;
    }

private:
    void _dfs(int i, int j, bool& isSubIsland, vector<vector<bool>>& visited, vector<vector<int>>& grid1,
              vector<vector<int>>& grid2) {
        if (i < 0 or j < 0 or i >= grid2.size() or j >= grid2[0].size() or grid2[i][j] != 1 or visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        if (grid1[i][j] != 1) {
            isSubIsland = false;
        }

        for (vector<int>& dir : _dirs) {
            int neighX = i + dir[0], neighY = j + dir[1];
            _dfs(neighX, neighY, isSubIsland, visited, grid1, grid2);
        }
    }

    vector<vector<int>> _dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};
