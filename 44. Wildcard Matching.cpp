// ***
//
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
//
// Note:
//
// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like ? or *.
// Example 1:
//
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:
//
// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.
// Example 3:
//
// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
// Example 4:
//
// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
// Example 5:
//
// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false
//
// ***

// dp[i][j] indicates whether the first i letters in s match the first j letters in p.
// dp needs size (s.size() + 1, p.size() + 1) because when s and p are both empty, they are considered match,
// so we initialize dp[0][0] to be true.
//
// Similar questions:
// 97. Interleaving String

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;

        // When s is empty and p has continuous stars, then all positions in dp where s is empty and there is a
        // continuous star in p are true because stars in p can match empty s.
        for (int j = 1; j <= p.size(); ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] == '*') {
                    // If the j-th letter in p is a "*", then first i letters in s will match first j letters in p:
                    // - when first i - 1 letters in s match first j letters in p
                    // (because the j-th letter of p is a "*", we can match more letters in s), OR
                    // - when first i letters in s match first j - 1 letters in p
                    // (because the j-th letter of p is a "*", p[0:j] can match whatever p[0:j-1] matches)
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    // If we do not see a star at j-th letter in p,
                    // we just comapre whether the i-th letter in s equal to the j-th letter in p.
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};
