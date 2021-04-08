// ***
//
// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
// Example 2:
// Input: "cbbd"
// Output: "bb"
//
// ***
//
// Note: this question is different from 516. Longest Palindromic Subsequence.


// TODO: not done
// DP
// dp[i][j]: whether s[j, i] is a palindrome
// 我们维护一个二维数组 dp，其中 dp[i][j] 表示字符串区间 [j, i] 是否为回文串，当 i = j
// 时，只有一个字符，肯定是回文串，如果 i = j + 1，说明是相邻字符，此时需要判断 s[i] 是否等于 s[j]，如果i和j不相邻，即 i
// - j >= 2 时，除了判断 s[i] 和 s[j] 相等之外，dp[i - 1][j + 1] 若为真，就是回文串
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, len = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i][j] = (s[i] == s[j] && (i - j < 2 || dp[i - 1][j + 1]));
                if (dp[i][j] && len < i - j + 1) {
                    len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, len);
    }
};

// Brute force solution, worst case O(n^2), works pretty well.
// The idea is that, for every letter in s, treat it as the center of a palindrom.
// The palindrom can be either an odd palindrome like "aba" or an even palindrome like "abba".
// We extend that palindrom and see what length we can get, record the start position and the length.
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 0;

        for (int i = 0; i < s.size(); ++i) {
            // Assume the palindrom is odd from current position.
            _extendPalindrome(s, i, i, start, maxLength);

            // Assume the palindrom is even from current position.
            _extendPalindrome(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }

private:
    void _extendPalindrome(const string& s, int i, int j, int& start, int& maxLength) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i, ++j;
        }

        // After while loop, i and j are pointing to different letters:
        // a a a l e v e l b b b
        //     ^           ^
        //     i           j
        //
        // For odd palindrome, the length is at least 1 (the number itself)
        // For even palindrom, the length is at least 0
        int currentLength = j - i - 1;
        if (currentLength > maxLength) {
            start = i + 1;
            maxLength = currentLength;
        }
    }
};
