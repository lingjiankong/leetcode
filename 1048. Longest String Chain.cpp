// ***
//
// You are given an array of words where each word consists of lowercase English letters.
//
// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing
// the order of the other characters to make it equal to wordB.
//
// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2,
// word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.
//
// Return the length of the longest possible word chain with words chosen from the given list of words.
//
//
// Example 1:
//
// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
//
//
// Example 2:
//
// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
//
//
// Example 3:
//
// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.
//
//
// Constraints:
//
// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.
//
// ***

// First, sort words based on word length.
// dp[i]: longest word chain that ends with dp[i].
//
// Base condition:
// dp[i] = 1: Every element in dp is at least 1 because a word by itself is a longest word chain of size 1.
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.size() < b.size(); });

        vector<int> dp(words.size(), 1);

        int maxLen = 1;

        for (int i = 1; i < words.size(); ++i) {
            // Traverse from right to left (decreasing word size)
            for (int j = i - 1; j >= 0; --j) {
                // These are just optimizations.
                if (words[j].size() == words[i].size()) {
                    continue;
                } else if (words[j].size() + 1 < words[i].size()) {
                    break;
                }

                // words[j].size() + 1 = words[i].size()
                if (isPredecessor(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLen = max(maxLen, dp[i]);
                }
            }
        }

        return maxLen;
    }

private:
    // Return true if wordA is a predecessor of wordB
    bool isPredecessor(const string& wordA, const string& wordB) {
        int i = 0, j = 0;
        while (j < wordB.size()) {
            if (wordA[i] == wordB[j]) {
                ++i;
            }
            ++j;
        }

        return i == wordA.size();
    }
};

// Another DP method. Tree traversal.
// dfs(word): longest possible word chain that ends in "word".
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> allWords(words.begin(), words.end());
        unordered_map<string, int> memo;

        int maxLen = 1;
        for (string word : words) {
            maxLen = max(maxLen, dfs(word, memo, allWords));
        }

        return maxLen;
    }

private:
    int dfs(const string& word, unordered_map<string, int>& memo, const unordered_set<string>& allWords) {
        // Leaf of the tree. A word of single letter has a chain length of 1.
        if (word.size() == 1) {
            return 1;
        }

        if (memo.count(word)) {
            return memo[word];
        }

        int maxLen = 1;
        for (int i = 0; i < word.size(); ++i) {
            string candidate = word.substr(0, i) + word.substr(i + 1);
            if (allWords.count(candidate)) {
                maxLen = max(maxLen, dfs(candidate, memo, allWords) + 1);
            }
        }

        return memo[word] = maxLen;
    }
};
