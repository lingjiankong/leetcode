// ***
//
// A robot is located at the top-left corner of a m x n grid.
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid.
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
// ***
//
// See also 62. Unique Paths.
//
// In this question, we also initialize the top row and left column to 1.
//
// However, because their might be obstacle, we will break as soon as we see an obstacle in
// top row of left column during initialization.

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize first column to 1 until obstacle.
    for (int i = 0; i < m; ++i) {
        if (obstacleGrid[i][0]) {
            break;
        }

        dp[i][0] = 1;
    }

    // Initialize first row to 1 until obstacle.
    for (int j = 0; j < n; ++j) {
        if (obstacleGrid[0][j]) {
            break;
        }

        dp[0][j] = 1;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (!obstacleGrid[i][j]) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}
