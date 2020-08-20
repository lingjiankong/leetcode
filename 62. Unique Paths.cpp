// ***
//
// A robot is located at the top-left corner of a m x n grid.
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid.
// How many possible unique paths are there?
//
// ***
//
// Some math:
// Total steps must be m + n - 2, during each step, you can either move down or move right.
// Among these m + n - 2, you must choose exactly m - 1 steps to move down (therefore n - 1 steps to move right)
// Choosing m - 1 objects out of m + n - 2 objects is simply C(m + n - 2, m - 1) = C(m + n - 2, n - 1)
// n Choose k = n! / (k! * (n-k)!) = ( m + n - 2)! / (( m - 1)! * (n - 1)!)
//
// dp[i][j]: number of unique path to reach i j
// See N3. Unique Paths from Top Left to Bottom Right.

int uniquePaths(int m, int n) {
    // Remember to initialize the top row and left column to 1.
    // So you could just initialize to whole grid to 1.
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}
