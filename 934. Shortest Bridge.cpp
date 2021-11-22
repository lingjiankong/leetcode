// ***
//
// In a given 2D binary array grid, there are two islands.  (An island is a 4-directionally connected group of 1s not
// connected to any other 1s.) Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.
// Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)
//
//
// Example 1:
//
// Input: grid = [[0,1],[1,0]]
// Output: 1
//
//
// Example 2:
//
// Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2
//
//
// Example 3:
//
// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1
//
//
// Constraints:
//
// 2 <= grid.length == grid[0].length <= 100
// grid[i][j] == 0 or grid[i][j] == 1
//
// ***

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<vector<int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n));

        // DFS first island, convert everything to 2 and push to queue.
        bool found = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (not found and grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                    grid[i][j] = 2;

                    _dfs(grid, i, j, q, visited);

                    found = true;
                }
            }
        }

        // BFS island 2 until you meet island 1.
        int steps = -1;
        while (not q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                vector<int> cur = q.front();
                q.pop();
                int i = cur[0], j = cur[1];

                if (grid[i][j] == 1) {
                    return steps;
                }

                for (vector<int>& dir : _dirs) {
                    int neighX = i + dir[0], neighY = j + dir[1];
                    if (0 <= neighX and neighX < m and 0 <= neighY and neighY < n and not visited[neighX][neighY]) {
                        visited[neighX][neighY] = true;
                        q.push({neighX, neighY});
                    }
                }
            }
            ++steps;
        }

        return -1;
    }

private:
    void _dfs(vector<vector<int>>& grid, int i, int j, queue<vector<int>>& q, vector<vector<bool>>& visited) {
        for (vector<int>& dir : _dirs) {
            int neighX = i + dir[0], neighY = j + dir[1];
            int m = grid.size(), n = grid[0].size();
            if (0 <= neighX and neighX < m and 0 <= neighY and neighY < n and not visited[neighX][neighY] and
                grid[neighX][neighY] == 1) {
                grid[neighX][neighY] = 2;
                q.push({neighX, neighY});
                visited[neighX][neighY] = true;

                _dfs(grid, neighX, neighY, q, visited);
            }
        }
    }

    vector<vector<int>> _dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};

