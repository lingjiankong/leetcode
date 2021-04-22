// ***
//
// Given a string s. In one step you can insert any character at any index of the string.
// Return the minimum number of steps to make s palindrome.
// A Palindrome String is one that reads the same backward as well as forward.
//
// Example 1:
// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we don't need any insertions.
//
// Example 2:
// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
//
// Example 3:
// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".
//
// Example 4:
// Input: s = "g"
// Output: 0
//
// Example 5:
// Input: s = "no"
// Output: 1
//
// ***

// dp[i][j]: least number of insertions needed to turn dp[i:j] into a palindrom
// base case: dp[i][i] = 0 (since a letter by itself is already a palindrome)
// state transition function: see labuladong book pp.148.
// Traverse upper right half of the dp table from bottom to top, left to right
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }

        return dp[0][n - 1];
    }
};

// Same idea.
// dp[i][j]: least number of insersions needed to turn dp[j:i] into a palindrome
// Traverse from lower left half of the dp table from top to bottom, right to left.
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i - 1][j + 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + 1;
                }
            }
        }

        return dp[n - 1][0];
    }
};

