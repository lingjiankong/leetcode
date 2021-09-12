// ***
//
// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets
// such that the sum of elements in both subsets is equal.
//
//
// Example 1:
//
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//
// Example 2:
//
// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
//
//
// Constraints:
//
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100
//
// ***

// This is a 0-1 knapsack problem. See N4. 0-1 Knapsack.
//
// You want to find whether you can place nums into a knapsack of capacity sum / 2,
// so that a subset of nums has exactly capacity w.
//
// dp[i][w]: true if a subset of the first i items has exactly capacity w.
// Example: dp[4][9] = true, means if you choose among the first 4 weights, there is a way to choose a subset from the
// first 4 weights such that the weights sum to exactly 9. (e.g. weights = [2, 4, 5, 6], you can choose subset [4, 5])
//
// Base case:
// dp[0][0] = true
// dp[i][0] = true: when weight capacity is 0, you can put 0 items in the knapsack (the knapsack is already full).
// dp[0][w] = false: there is no item to select to reach weight capacity w.
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // Impossible to partiion odd number it two subsets of equal sum.
        if (sum % 2 != 0) {
            return false;
        }

        return knapsack(sum / 2, nums.size(), nums);
    }

private:
    bool knapsack(int W, int N, const vector<int>& weights) {
        vector<vector<bool>> dp(N + 1, vector<bool>(W + 1));

        for (int i = 0; i <= N; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= N; ++i) {
            for (int w = 1; w <= W; ++w) {
                if (w - weights[i - 1] < 0) {
                    // there is no enough space in the knapsack. You cannot put item i into the knapsack.
                    dp[i][w] = dp[i - 1][w];
                } else {
                    // either put item i into the knapsack, or not.
                    dp[i][w] = dp[i - 1][w - weights[i - 1]] or dp[i - 1][w];
                }
            }
        }

        return dp[N][W];
    }
};
