// ***
//
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
// determine if s can be segmented into a space-separated sequence of one or more dictionary words.
//
// Note:
//
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
// Example 1:
//
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:
//
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.
// Example 3:
//
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false
//
// ***

// Recursion with memoization.
//
// We split a given string at every possible index (startIndex), check if the front portion of that string is in the
// dictionary: if it is found in the dictionary, then the recursive function is called for the remaining portion of the
// string. startIndex is where we want to split the string. If startIndex == s.size(), then it means everything before
// startIndex can be partitioned, so return true. cache[i] stores whether the substring s[0, i) can be partitioned.
class Solution {
public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, bool> cache;
        int startIndex = 0;

        return _dfs(startIndex, s, wordSet, cache);
    }

private:
    bool _dfs(int startIndex, const string& s, const unordered_set<string>& wordSet, unordered_map<int, bool>& cache) {
        // When startIndex == s.size(), there is nothing to the right of the index, therefore, _dfs returns true.
        if (startIndex == s.size()) {
            return true;
        }

        if (cache.count(startIndex)) {
            return cache[startIndex];
        }

        for (int i = 1; i <= s.size() - startIndex; ++i) {
            if (wordSet.count(s.substr(startIndex, i)) and _dfs(startIndex + i, s, wordSet, cache)) {
                return cache[i] = true;
            }
        }

        return cache[startIndex] = false;
    }
};

// Dynamic programming solution:
// Consider substring s[0, i), enumerate all j which partitions the
// this substring into smaller substring s[0, j) and s[j, i).
//
// dp[i]: whether the substring s[0, i) can be partitioned.
// dp[0] = true because an empty string can always be partitioned.
class Solution {
public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] and wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;  // we can break as soon as dp[i] = true
                }
            }
        }
        return dp.back();
    }
};
