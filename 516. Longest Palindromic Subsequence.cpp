// ***
//
// Given a string s, find the longest palindromic subsequence's length in s.
//
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without
// changing the order of the remaining elements.
//
//
//
// Example 1:
//
// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:
//
// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
// Note: this question is different from 5. Longest Palindromic Substring.
//
// ***

// dp[i][j]: longest palindrome subsequence formed by s[i:j]
// Base case: dp[i][j] = 1 where i == j since a letter by itself is a palindrom string of length 1.
//
// Note that we are only interested in upper right half of the dp table (where i <= j),
// and we traverse from bottom to top, left to right.
//
// See labuladong book pp. 140.
//
// See also 5. Longest Palindromic Substring.
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Initialize the diagonal.
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Traverse the upper right half of the dp table from bottom up.
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

// Same idea, swap the meaning of i and j.
// dp[i][j]: longest palindrome subsequence formed by s[j:i]
// Now you are only interested in the lower left half of the dp table (where j <= i), and we traverse from top to
// bottom, right to left.
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Initialize the diagonal.
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i - 1][j + 1] + 2;
                } else {
                    dp[i][j] = max(dp[i][j + 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n - 1][0];
    }
};

