// ***
//
// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
// Example:
//
// Input:
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Output: 4 at (i, j).
//
// ***
//
// dp[i][j] is the longest edge of the square which bottom right corner is at (i, j).
//
int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n));

    int longestEdge = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Needs if (i == 0 || j == 0) inside the for loop because we need to assign longestEdge.
            // For example, in the case of matrix = [["1"]].
            if (i == 0 || j == 0) {
                dp[i][j] = matrix[i][j] - '0';
            } else if (matrix[i][j] == '1') {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }

            longestEdge = max(longestEdge, dp[i][j]);
        }
    }

    return pow(longestEdge, 2);
}
