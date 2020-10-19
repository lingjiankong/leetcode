// ***
//
// Given a m x n grid filled with non-negative numbers,
// find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example:
//
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
//
// Explanation: Because the path 1→ 3→ 1→ 1→ 1 minimizes the sum.
//
// ***

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp = grid;

    for (int i = 1; i < grid.size(); ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    for (int j = 1; j < grid[0].size(); ++j) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    for (int i = 1; i < grid.size(); ++i) {
        for (int j = 1; j < grid[0].size(); ++j) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    return dp.back().back();
}
