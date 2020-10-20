// ***
//
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// Example 1:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
//
// Example 2:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
//
// ***
//
// DP array for the first example given in the problem:
//
//   Ø d b b c a
// Ø T F F F F F
// a T F F F F F
// a T T T T T F
// b F T T F T F
// c F F T T T T
// c F F F T F T
//
// The index of dp and s1 s2 s3 is a bit confusing since dp has one more element in each dimension,
// If you read the code carefully you should understand it.
// s1[i - 1]: i-th letter in s1
// s2[j - 1]: j-th letter in s2
// dp[i][j]: Whether the first (i + j) letters of s3 can be formed by
// interleaving the first i letters of s1 and the first j letters of s2.
//
// Similar questions:
// 44. Wildcard Matching.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        // An empty s3 can be formed by an empty s1 + an empty s2.
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        dp[0][0] = true;

        // If s2 is empty, then to test whether s3 can be formed by s1,
        // we just need to to compare whether s1[i-1] == s3[i-1] (once they are not equal then the rest will be false).
        for (int i = 1; i <= s1.size(); ++i) {
            if (s1[i - 1] != s3[i - 1]) {
                break;
            }
            dp[i][0] = true;
        }

        // Same idea as previous for loop.
        for (int j = 1; j <= s2.size(); ++j) {
            if (s2[j - 1] != s3[j - 1]) {
                break;
            }
            dp[0][j] = true;
        }

        // If first i-1 letters in s1 + first j letters in s2 are able to form first i-1+j letters in s3
        // (indicated by dp[i-1][j] = true),
        // AND if the i-th letter in s1 == the (i + j)-th letter in s3
        // (indicated by s1[i-1] == s3[i-1+j]:
        // then the first i letters in s1 + first j letters in s2 will form first i+j letters in s3.
        // Same idea for s2 and s3.
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[s1.size()][s2.size()];
    }
};
