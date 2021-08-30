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
// Note: this question is similar but different from 516. Longest Palindromic Subsequence.

// DP
// dp[i][j]: whether s[j:i] is a palindrome
// 我们维护一个二维数组 dp，其中 dp[i][j] 表示字符串区间 [j, i] 是否为回文串，当 i = j
// 时，只有一个字符，肯定是回文串，如果 i = j + 1，说明是相邻字符，此时需要判断 s[i] 是否等于 s[j]，如果i和j不相邻，即 i
// - j >= 2 时，除了判断 s[i] 和 s[j] 相等之外，dp[i - 1][j + 1] 若为真，s[j:i]就是回文串
//
// Note that we are only interested in the lower left half of the dp table (where j <= i),
// and we traverse from top to bottom, left to right.
//
// See also 516. Longest Palindromic Subsequence.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxLen = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[i] == s[j]) {
                    if (j + 1 == i or dp[i - 1][j + 1]) {
                        dp[i][j] = true;

                        if (maxLen < i - j + 1) {
                            maxLen = i - j + 1;
                            start = j;
                        }
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

// Same idea. dp[i][j]: whether s[i:j] is a palindrome.
// Now we are only interested in the upper right half of the dp table (where i <= j),
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxLen = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    if (i + 1 == j or dp[i + 1][j - 1]) {
                        dp[i][j] = true;

                        if (maxLen < j - i + 1) {
                            maxLen = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
        }

        return s.substr(start, maxLen);
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
