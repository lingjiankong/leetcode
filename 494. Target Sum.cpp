// ***
//
// You are given an integer array nums and an integer target.
//
// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and
// then concatenate all the integers.
//
// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the
// expression "+2-1". Return the number of different expressions that you can build, which evaluates to target.
//
//
// Example 1:
//
// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
//
//
// Example 2:
//
// Input: nums = [1], target = 1
// Output: 1
//
//
// Constraints:
//
// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000
//
// ***

// Naive backtracking, TLE
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        backtrack(0, nums, 0, target, total);
        return total;
    }

private:
    void backtrack(int start, const vector<int>& nums, int curTotal, int& target, int& total) {
        if (start == nums.size() and curTotal == target) {
            total += 1;
            return;
        }

        backtrack(start + 1, nums, curTotal + nums[i], target, total);
        backtrack(start + 1, nums, curTotal - nums[i], target, total);
    }
};

// Recursion with memoization
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, unordered_map<int, int>> memo;
        return dfs(nums, target, 0, memo);
    }

private:
    int dfs(vector<int>& nums, int sum, int start, unordered_map<int, unordered_map<int, int>>& memo) {
        if (start == nums.size()) {
            return sum == 0;
        }

        if (memo[start].count(sum)) {
            return memo[start][sum];
        }

        int count1 = dfs(nums, sum - nums[start], start + 1, memo);
        int count2 = dfs(nums, sum + nums[start], start + 1, memo);
        return memo[start][sum] = count1 + count2;
    }
};

// Dynamic programming:
// Partition nums into two subset: A subset are numbers assigned '+'; B subset are numbers assigned '-'.
//
// Therefore we have:
// sum(A) - sum(B) = target
// sum(A) = target + sum(B)
// sum(A) + sum(A) = target + sum(B) + sum(A)
// 2 * sum(A) = target + sum(nums)
// sum(A) = (target + sum(nums)) / 2
//
// This is equivalent to a knapsack problem:
// Given array nums, find the number of subset which sum equals to goal = (target + sum(nums)) / 2.
//
// In knapsack lanuages:
// Given a list of item weight nums, and knapsack capacity of (target + sum(nums)) / 2, find the number of ways to fill
// the knapsack exactly.
//
// See 518. Very similar but not the same (518 has unlimited amount of coin, however in this question you have a fixed
// of nums to choose from, see index during state transition)
//
// dp[i][j]: Choosing only from the first i numbers in nums, how many subsets are there which sum exactly to j.
// i.e. Choosing only the first i items in weights, how many ways to fill a knapsack of exactly j capacity.
//
// Base condition:
// dp[0][0] = 1, dp[i][0] = 1: The only way to make up sum of 0 is not choosing anything
// dp[0][j] = 0, No number to choose from, therefore no way to make up sum of j
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if ((sum + target) % 2 != 0 or (sum + target) / 2 < target) {
            return 0;
        }

        return knapsack(nums, goal);
    }

private:
    int knapsack(vector<int>& nums, int goal) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(goal + 1));

        for (int i = 0; i <= nums.size(); ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 0; j <= goal; ++j) {
                if (j - nums[i - 1] < 0) {
                    // Cannot choose the ith number, the number itself is large than sum
                    // (i.e., there is no space in the knapsack)
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // Either choose of not choose the ith number.
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
            }
        }

        return dp[nums.size()][goal];
    }
};
