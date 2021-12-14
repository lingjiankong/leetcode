// ***
//
// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1,
// col1) and lower right corner (row2, col2).
//
// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]
//
// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
//
// Note:
// You may assume that the matrix does not change.
// There are many calls to sumRegion function.
// You may assume that row1 ≤ row2 and col1 ≤ col2.
//
// ***
//
// +-----+-+-------+     +--------+-----+     +-----+---------+     +-----+--------+
// |     | |       |     |        |     |     |     |         |     |     |        |
// |     | |       |     |        |     |     |     |         |     |     |        |
// +-----+-+       |     +--------+     |     |     |         |     +-----+        |
// |     | |       |  =  |              |  +  |     |         |  -  |              |
// +-----+-+       |     |              |     +-----+         |     |              |
// |               |     |              |     |               |     |              |
// |               |     |              |     |               |     |              |
// +---------------+     +--------------+     +---------------+     +--------------+
//
//      dp[i][j]      =     dp[i-1][j]     +     dp[i][j-1]      -    dp[i-1][j-1]    +    matrix[i-1][j-1]
//
// So, we use the same idea to find the specific area's sum.
// +---------------+   +--------------+   +---------------+   +--------------+   +--------------+
// |               |   |         |    |   |   |           |   |         |    |   |   |          |
// |   (r1,c1)     |   |         |    |   |   |           |   |         |    |   |   |          |
// |   +------+    |   |         |    |   |   |           |   +---------+    |   +---+          |
// |   |      |    | = |         |    | - |   |           | - |      (r1,c2) | + |   (r1,c1)    |
// |   |      |    |   |         |    |   |   |           |   |              |   |              |
// |   +------+    |   +---------+    |   +---+           |   |              |   |              |
// |        (r2,c2)|   |       (r2,c2)|   |   (r2,c1)     |   |              |   |              |
// +---------------+   +--------------+   +---------------+   +--------------+   +--------------+
//
// Note that, size of dp is [matrix.size() + 1, matirx[0].size() + 1] because we need the first row and first column
// to represent what the sum is when we have 0 elements.
//
// dp[i+1][j+1] represents the sum of area from matrix[0][0] to matrix[i][j] (inclusive).

class NumMatrix {
public:
    NumMatrix(const vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }

        dp.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }

private:
    vector<vector<int>> dp;
};
