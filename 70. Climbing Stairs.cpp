// ***
//
// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
// Note: Given n will be a positive integer.
//
// Example 1:
//
// Input: 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
// Example 2:
//
// Input: 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
//
// ***
//
// dp[i]: distinct ways to climb to stair i.
// dp[i] = dp[i-1] + dp[i-2], the sum of distinct ways of climbing to the previous two stairs.
//
// This question is basically Fibonacci number.
// The problem specified that n is a positive number.
//
// Number of stairs:        0 0 1 2 3 4 5 6 ...
// Number of ways to climb: 0 1 1 2 3 5 8 13 ...
// 					          ^ ^
//                            a b

int climbStairs(int n) {
    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp.back();
}

// O(1) space.
int climbStairs(int n) {
    int a = 1;
    int b = 1;

    for (int i = 2; i <= n; ++i) {
        int newB = a + b;
        a = b;
        b = newB;
    }

    return b;
}
