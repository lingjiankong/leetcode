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

// Sliding window.
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

// Same idea.
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
