// ***
//
// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.
//
// Example 1:
//
// Input: word1 = "sea", word2 = "eat"
// Output: 2
//
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
//
// Example 2:
//
// Input: word1 = "leetcode", word2 = "etco"
// Output: 4
//
// ***

// Using 1143. Longest Common Subsequence.
// dp[i][j]: longest common subsequence between word1[0:i) and word2[0,j)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return m + n - dp[m][n] * 2;
    }
};

// Without using 1143. Longest Common Subsequence.
// dp[i][j]: minimum number of steps to make word1[0:i) and word2[0:j) the same.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[m][n];
    }
};

