// ***
//
// Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.
//
// If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple
// such minimum-length windows, return the one with the left-most starting index.
//
// Example 1:
//
// Input:
// S = "abcdebdde", T = "bde"
// Output: "bcde"
// Explanation:
// "bcde" is the answer because it occurs before "bdde" which has the same length.
// "deb" is not a smaller window because the elements of T in the window must occur in order.
//
// ***

//    ∅  b  d
// ∅  0 -1 -1
// d  1 -1 -1
// b  2  1 -1
// d  3  1  1
//
// Not straightforward to understand.
//
// dp[i][j]: starting index of subsequence in S where S[0,i) contains everything in T[0,j), if it doesn't exist, then
// -1. For example, S = supearman, T = person, then dp[6][3] = 2, indicating superman[2:6) (pear) contains subsequence
// person[0:3) (per)
//
// Base condition: dp[i][0] = 0. The starting index for S to match a empty subsequence T is just the length of S.
// For example, S = supearman, T = person dp[9][0] = 9, indicating the start index to contain an empty subsequence is
// just the right bound of the array.
//
// Also, sincn S.size() must be >= T.size(), we are only interested in lower left triangle of the dp array where i >= j.
// So during initialization, only the first column needs to be initialized. Everything in upper right triangle would be
// -1.
//
// State transition: see equation.
class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }

        int start = -1, minLen = INT_MAX;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= min(i, n); ++j) {
                dp[i][j] = (S[i - 1] == T[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j];
            }

            // After finishing traversing every row, if dp[i][n] != -1, it indicates that
            // S[0,i) successfully contains subsequence T[0:j). In this case, update minLen.
            if (dp[i][n] != -1) {
                int len = i - dp[i][n];
                if (minLen > len) {
                    minLen = len;
                    start = dp[i][n];
                }
            }
        }

        return (start != -1) ? S.substr(start, minLen) : "";
    }
};

// Sliding window. Not typical, no need to understand.
class Solution {
public:
    string minWindow(string S, string T) {
        int start = INT_MIN, minLen = INT_MAX;
        int i = 0, j = 0;
        while (i < S.size()) {
            if (S[i] == T[j]) {
                if (j == T.size() - 1) {
                    int end = i + 1;
                    // Trace from right to left
                    while (j >= 0) {
                        if (S[i] == T[j]) {
                            --i;
                            --j;
                        } else {
                            --i;
                        }
                    }

                    ++i;
                    ++j;
                    // after ++i and ++j (j always = 0 now), we have S[i] == T[0],
                    if (end - i < minLen) {
                        minLen = end - i;
                        start = i;
                    }
                } else {
                    ++j;
                }
            }
            ++i;
        }

        return start == INT_MIN ? "" : S.substr(start, minLen);
    }
};

// Same idea. Not typical, no need to understand.
class Solution {
public:
    string minWindow(string S, string T) {
        int start = INT_MIN, minLen = INT_MAX;
        int i = 0, j = 0;
        while (i < S.size()) {
            if (S[i] == T[j]) {
                if (++j == T.size()) {
                    int end = i + 1;
                    // Trace from right to left
                    while (--j >= 0) {
                        while (S[i--] != T[j])
                            ;
                    }
                    ++i;
                    ++j;
                    // after ++i and ++j (j always = 0 now), we have S[i] == T[0],
                    if (end - i < minLen) {
                        minLen = end - i;
                        start = i;
                    }
                }
            }
            ++i;
        }

        return start == INT_MIN ? "" : S.substr(start, minLen);
    }
};
