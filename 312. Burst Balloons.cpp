// ***
//
// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an
// array nums. You are asked to burst all the balloons.
//
// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of
// bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
//
// Return the maximum coins you can collect by bursting the balloons wisely.
//
//
// Example 1:
//
// Input: nums = [3,1,5,8]
// Output: 167
//
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
//
// Example 2:
//
// Input: nums = [1,5]
// Output: 10
//
//
// Constraints:
//
// n == nums.length
// 1 <= n <= 500
// 0 <= nums[i] <= 100
//
// ***

// See labuladong book pp. 181.
// dp[i][j]: number of coins we are going to have by bursting all balloons in (i, j)
//
// Base case:
// dp[i][j] = 0 where i == j since there's no balloon in (i, j).
// dp[i][j] = 0 where i + 1 == j since there's no balloon in (i, j).
//
// 0 0 X X X X X
// X 0 0 X X X X
// X X 0 0 X X X
// X X X 0 0 X X
// X X X X 0 0 X
// X X X X X 0 0
// X X X X X X 0
//
// We only need to traverse upper right of the dp table, from left to right, bottom to top.
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> points(nums.size() + 2, 1);
        for (int i = 1; i <= nums.size(); ++i) {
            points[i] = nums[i - 1];
        }

        int n = points.size();

        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 3; i >= 0; --i) {
            for (int j = i + 2; j < n; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    // k is the last ballon to be burst in (i, j)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + points[i] * points[k] * points[j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

// Recursion. Should be correct but TLE.
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        points = vector<int>(nums.size() + 2, 1);

        for (int i = 1; i <= nums.size(); ++i) {
            points[i] = nums[i - 1];
        }

        return dp(0, points.size() - 1);
    }

private:
    int dp(int i, int j) {
        if (i == j) {
            return 0;
        }

        if (i + 1 == j) {
            return 0;
        }

        if (memo.count(i) and memo[i].count(j)) {
            return memo[i][j];
        }

        int res = 0;
        for (int k = i + 1; k < j; ++k) {
            res = max(res, dp(i, k) + dp(k, j) + points[i] * points[k] * points[j]);
        }

        return memo[i][j] = res;
    }

    unordered_map<int, unordered_map<int, int>> memo;

    vector<int> points;
};
