// ***
//
// You are given an integer array coins representing coins of different denominations and an integer amount representing
// a total amount of money.
//
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any
// combination of the coins, return 0.
//
// You may assume that you have an infinite number of each kind of coin.
//
// The answer is guaranteed to fit into a signed 32-bit integer.
//
// Example 1:
//
// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
//
// Example 2:
//
// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
//
// Example 3:
//
// Input: amount = 10, coins = [10]
// Output: 1
//
//
// Constraints:
//
// 1 <= coins.length <= 300
// 1 <= coins[i] <= 5000
// All the values of coins are unique.
// 0 <= amount <= 5000
//
// ***

// dp[i][j]: Using only a subset of first i coins, how many ways to make up exactly j amount.
// In knapsack language: Using only a subset of first i items, how many ways to make up exactly j weights
// Note: In this problem, you can use unlimited amount of items (coins)
//
// Base case:
// dp[0][0] = 1
// dp[0][j] = 0 since there is no coin to use.
// dp[i][0] = 1 since the only way to make up 0 amount is not using any coin

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (coins[i - 1] > j) {
                    // Coin i is larger than amount j. Cannot use the coin.
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // NOTICE the state transition function here is slightly different than regular knapsack problem
                    // (e.g. 416. Partition Equal Subset Sum)
                    //
                    // Not using the ith coin, only using the first i-1 coins to make up amount j, then we have
                    // dp[i-1][j] ways.
                    //
                    // Using the ith coin, since we can use unlimited same coin, we need to know how
                    // many ways to make up amount j - coins[i-1] by using first i coins (including ith), which is
                    // dp[i][j - coins[i-1]]
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[n][amount];
    }
};
