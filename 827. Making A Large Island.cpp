// ***
//
// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
// Return the size of the largest island in grid after applying this operation.
// An island is a 4-directionally connected group of 1s.
//
//
// Example 1:
//
// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
//
//
// Example 2:
//
// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
//
//
// Example 3:
//
// Input: grid = [[1,1],[1,1]]
// Output: 4
// Explanation: Can't change any 0 to 1, only one island with area = 4.
//
//
// Constraints:
//
// n == grid.length
// n == grid[i].length
// 1 <= n <= 500
// grid[i][j] is either 0 or 1.
//
// ***

// BFS. TLE. Not very efficient. The idea is helpful.
// For each 0, look at its neighbors and calculate the max area of islands we could have if we turn this 0 to 1.
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Edge case: if there is no zero at all, return the total number of elements in the grid.
        bool hasZero = false;
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int curArea = 0;

                    vector<vector<bool>> visited(m, vector<bool>(n, false));

                    grid[i][j] = 1;  // turn this grid into 1
                    _dfs(i, j, grid, visited, curArea);
                    grid[i][j] = 0;  // don't forget to turn it back to 0 after traversing.

                    maxArea = max(maxArea, curArea);
                    hasZero = true;
                }
            }
        }

        return hasZero ? maxArea : m * n;
    }

private:
    void _dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited, int& area) {
        if (x < 0 or y < 0 or x >= grid.size() or y >= grid[0].size() or visited[x][y] or grid[x][y] != 1) {
            return;
        }

        area += 1;
        visited[x][y] = true;

        for (vector<int>& dir : _dirs) {
            int neighX = x + dir[0], neighY = y + dir[1];
            _dfs(neighX, neighY, grid, visited, area);
        }
    }

    vector<vector<int>> _dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};

// Union-find, TLE but should be correct.
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        UnionFind<string> uf;
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // Connect all islands.
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

        // Find the total area if we turn a 0 to 1.
        int maxArea = 0;
        bool hasZero = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    int area = 1;
                    unordered_set<string> uniqueRoots;

                    for (vector<int>& dir : dirs) {
                        int neighX = i + dir[0], neighY = j + dir[1];

                        if (0 <= neighX and neighX < m and 0 <= neighY and neighY < n and grid[neighX][neighY] == 1) {
                            string neighPos = to_string(neighX) + "," + to_string(neighY);
                            uniqueRoots.insert(uf.findRoot(neighPos));
                        }
                    }

                    for (string& root : uniqueRoots) {
                        area += uf.size()[root];
                    }
                    maxArea = max(maxArea, area);
                    hasZero = true;
                }
            }
        }

        return hasZero ? maxArea : m * n;
    }
};
