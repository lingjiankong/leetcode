// ***
//
// Given a string s, find the longest palindromic subsequence's length in s.
// 
// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
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

// dp[i][j]: longest palindrome substring formed by s[i:j]
// Base case: dp[i][j] = 1 where i == j since a letter by itself is a palindrom string of length 1.
// Note that the lower left half of the dp table is not used since i < j doesn't mean anything
// When you are traversing the dp table, traverse the upper right half of the dp table from bottom up.
// See labuladong book pp. 140.
string longestPalindromeSubseq(string s) {
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

    return dp[0][n-1];
}

