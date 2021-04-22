// ***
//
// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'
// where:
//
// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
//
//
// Example 1:
//
// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
//
// Example 2:
//
// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
//
// Example 3:
//
// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
//
// Example 4:
//
// Input: s = "aab", p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
//
// Example 5:
//
// Input: s = "mississippi", p = "mis*is*p*."
// Output: false
//
//
// Constraints:
//
// 0 <= s.length <= 20
// 0 <= p.length <= 30
// s contains only lowercase English letters.
// p contains only lowercase English letters, '.', and '*'.
// It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
//
// ***

// Recursion
// See labuladong book pp. 155
// _dp(s, i, p, j): Whether s[i:) can be matched by p[j:)
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        return _dp(s, i, p, j);
    }

private:
    bool _dp(const string& s, int i, const string& p, int j) {
        int m = s.size(), n = p.size();

        // * base conditions *
        if (j == n) {
            return i == m;
        }
        if (i == m) {
            if ((n - j) % 2 == 1) {
                return false;
            }
            for (; j + 1 < n; j += 2) {
                if (p[j + 1] != '*') {
                    return false;
                }
            }
            return true;
        }

        string key = to_string(i) + "," + to_string(j);
        if (_memo.count(key)) {
            return _memo[key];
        }

        bool res = false;
        if (s[i] == p[j] || p[j] == '.') {
            if (j < n - 1 && p[j + 1] == '*') {
                res = _dp(s, i, p, j + 2) || _dp(s, i + 1, p, j);
            } else {
                res = _dp(s, i + 1, p, j + 1);
            }
        } else {
            if (j < n - 1 && p[j + 1] == '*') {
                res = _dp(s, i, p, j + 2);
            } else {
                res = false;
            }
        }

        return _memo[key] = res;
    }

    unordered_map<string, bool> _memo;
};

// Similar idea, using dp table.
// Might be not straightforward to understand.
//
// dp[i][j]: whether s[0: i) can be matched by p[0: j)
//
// base condition:
// dp[0][0] = true
// dp[i][0] = false since if p contains no regex then nothing in s can be mateched
//
// state transition function:
// 1. dp[i][j] = dp[i - 1][j - 1], if (s[i - 1] == p[j - 1] || p[j - 1] == '.');
// 2. dp[i][j] = dp[i][j - 2], if p[j - 1] == '*' and the pattern at p[j - 2] repeats for 0 times (i.e. skip this
// matching);
// 3. dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern at p[j -
// 2] repeats for at least 1 times.
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (j > 1 && p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                } else {
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
