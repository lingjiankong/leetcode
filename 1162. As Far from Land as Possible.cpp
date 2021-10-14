// ***
//
// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell
// such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in
// the grid, return -1.
//
// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is
// |x0 - x1| + |y0 - y1|.
//
//
// Example 1:
//
// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
//
//
// Example 2:
//
// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
//
//
// Constraints:
//
// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1
//
// ***

// Put *all* land cells (1) into a queue as source nodes and BFS for water cells (0),
// the last expanded one will be the farthest.
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        // Return -1 if there's no island or no water.
        if (q.size() == 0 or q.size() == n * n) {
            return -1;
        }

        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int step = -1;
        while (not q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                auto cur = q.front();
                q.pop();
                for (auto dir : dirs) {
                    int x = cur[0] + dir[0], y = cur[1] + dir[1];
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != 0) {
                        continue;
                    }
                    grid[x][y] = INT_MAX;  // mark water cell (0) as visited
                    q.push({x, y});        // push water cell (0) to queue for next level of BFS
                }
            }
            ++step;
        }

        return step;
    }
};
