// ***
//
// Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each
// step:
//
// Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
//
//
// Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted.
// Output the minimum number of steps to get n 'A'.
//
// Example 1:
//
// Input: 3
// Output: 3
// Explanation:
// Intitally, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.
//
//
// Note:
//
// The n will be in the range [1, 1000].
//
// ***
//
// AAAAAA can be obtained by
// AAA + 2 ops (copy AAA, then paste 1 time)
// AA + 3 ops (copy AA, then paste 2 times)
// A + 6 ops (copy A, then paste 5 times)

// dp[i]: minimum number of steps needed to get exactly i 'A's.
// base case: dp[0] = 0, dp[1] = 0
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; ++i) {
            dp[i] = i;  // in the worst case, you need i steps to get i 'A's (keep pasting 'A')
            for (int factor = 2; factor < i; ++factor) {
                if (i % factor == 0) {
                    dp[i] = min(dp[i], dp[i / factor] + factor);  // copy dp[i / factor] factor number of times
                }
            }
        }
        return dp[n];
    }
};

// Recursion
class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }

        int res = n;
        for (int factor = 2; factor <= n; ++factor) {
            if (n % factor == 0) {
                res = min(res, minSteps(n / factor) + factor);
            }
        }
        return res;
    }
};
