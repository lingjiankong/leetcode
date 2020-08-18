// ***
//
// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row
// below.
//
// For example, given the following triangle (I print it differently)
//
// [
//   [2],
//   [3,4],
//   [6,5,7],
//   [4,1,8,3]
// ]
//
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// ***
//
// Use bottom-up dp approach. Very intuitive once you understand the code.

int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> dp = triangle.back();

    for (int row = triangle.size() - 2; row >= 0; --row) {
        for (int col = 0; col <= row; ++col) {
            dp[col] = min(dp[col], dp[col + 1]) + triangle[row][col];
        }
    }

    return dp[0];
}
