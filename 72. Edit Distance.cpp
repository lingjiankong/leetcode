// ***
//
// Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
//
// You have the following 3 operations permitted on a word:
//
// Insert a character
// Delete a character
// Replace a character
//
// Example 1:
// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
//
// Example 2:
// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
//
// ***

// dp[i][j] stores the minimum edit distance to convert word1[0, i) to word2[0, j)
//
// Base case:
// word1 = "", word2 = "ros"
// 1. If word1 is empty, then the min edit distance is word2.size() (insertion).
//
// word1 = "horse", word2 = ""
// 2. If word2 is empty, then the min edit distance is word1.size() (deletion).
//
// State transition:
// word1 = "hors", word2 = "ros"
// 3. If word1[i-1] = word2[j-1] (i.e. last letter is the same),
// then the min edit distance = dp[i-1][j-1] (skip).
// That is, the min edit distance for (word1 = "hors", word2 = "ros")
// is the same as the min edit distance for (word1 = "hor", word2 = "ro").
//
// word1 = "horse", word2 = "ros"
// 4. If word1[i-1] != word2[j-1] (i.e. last letter not the same),
// then the min edit distance is: dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1, where
//
// a). dp[i][j-1] stores the edit distance between (horse, ro), so ros can be obtained by insertion to s1.
// You know how to go from horse -> ro,
// so you can insert s to horse to get to ros.
//
// b). dp[i-1][j] stores the edit distance between (hors, ros), so ros can be obtained by deletion from s1.
// You know how to go from hors -> ros,
// so you can delete e from horse to get to ros.
//
// c). dp[i-1][j-1] stores the edit distance between (hors, ro), so ros can be obtained by replacement
// You know how to go from hors -> ro, which indicates "horse" can go to "roe",
// so you can replace e in horse with s to get to ros.
//
//   Ø a b c d
// Ø 0 1 2 3 4
// b 1 1 1 2 3
// b 2 2 1 2 3
// c 3 3 2 1 2
//
int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }

    return dp[m][n];
}

// Same idea. Recursion from labuladong. See book pp. 124 for detail.
// No need to understand. Understanding dp table solution is sufficient.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        _memo = vector<vector<int>>(m, vector<int>(n, -1));

        return _dp(word1, word2, m - 1, n - 1);
    }

private:
    int _dp(const string& word1, const string& word2, int i, int j) {
        if (i == -1) {
            return j + 1;
        }
        if (j == -1) {
            return i + 1;
        }
        if (_memo[i][j] != -1) {
            return _memo[i][j];
        }

        if (word1[i] == word2[j]) {
            return _memo[i][j] = _dp(word1, word2, i - 1, j - 1);
        } else {
            return _memo[i][j] = min({_dp(word1, word2, i, j - 1) + 1,        // insert word2[j] to word1[i]
                                      _dp(word1, word2, i - 1, j) + 1,        // delete word1[i]
                                      _dp(word1, word2, i - 1, j - 1) + 1});  // replace word1[i] with word2[j]
        }
    }

    vector<vector<int>> _memo;
};
