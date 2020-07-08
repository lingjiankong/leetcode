// ***
//
// Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of
// the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of
// "ABCDE" while "AEC" is not).
//
// It's guaranteed the answer fits on a 32-bit signed integer.
//
// Example 1:
//
// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)
//
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
// Example 2:
//
// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)
//
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^
//
// ***
//
//   Ø r a b b b i t
// Ø 1 1 1 1 1 1 1 1
// r 0 1 1 1 1 1 1 1
// a 0 0 1 1 1 1 1 1
// b 0 0 0 1 2 3 3 3
// b 0 0 0 0 1 3 3 3
// i 0 0 0 0 0 0 3 3
// t 0 0 0 0 0 0 0 3
//
// dp[i][j]: *number of* distinct subsequence of first i letters in t can be formed by first j letters in s.
// dp[0][0] = 1 because an empty string is a subsequence of an empty string.
// dp[i][0] = 0 because a non-empty string cannot be formed by an empty string.

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>> dp(t.size() + 1, vector<long>(s.size() + 1));

        for (int j = 0; j <= s.size(); ++j) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= t.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                // The number of distinct subsequence of first i letters in t formed by first j letters in s must be at
                // least as many as the number of distinct subsequence of first i letters in t formed by first j - 1
                // letters in s.
                //
                // if the i-th letter in t is the same as the j-th letter in s, then
                // dp[i][j] = dp[i][j-1] + dp[i-1][j-1]. Otherwise,
                // dp[i][j] = dp[i][j-1]
                //
                // You obtain the state transition function mostly by observation, there is nothing really obvious.
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }

        return dp[t.size()][s.size()];
    }
};
