// ***
//
// Given an integer matrix, find the length of the longest increasing path.
//
// From each cell, you can either move to four directions: left, right, up or down.
// You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
//
// Example 1:
// Input: nums =
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
//
// Example 2:
// Input: nums =
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//
// ***

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int m = matrix.size(), n = matrix[0].size();

        int maxLen = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxLen = max(maxLen, _dfs(matrix, i, j));
            }
        }

        return maxLen;
    }

private:
    int _dfs(vector<vector<int>>& matrix, int x, int y) {
        if (_cache.count(x) and _cache[x].count(y)) {
            return _cache[x][y];
        }

        int m = matrix.size(), n = matrix[0].size();

        int maxLen = 1;
        for (vector<int>& dir : _dirs) {
            int neighX = x + dir[0], neighY = y + dir[1];
            if (neighX < 0 || neighX >= m || neighY < 0 || neighY >= n || matrix[x][y] >= matrix[neighX][neighY]) {
                continue;
            }
            int curLen = 1 + _dfs(matrix, neighX, neighY);
            maxLen = max(maxLen, curLen);
        }

        return _cache[x][y] = maxLen;
    }

    vector<vector<int>> _dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    // _cache[i][j] is the longest increasing path which starts in i, j.
    unordered_map<int, unordered_map<int, int>> _cache;
};
