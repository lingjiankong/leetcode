// ***
//
// Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.
//
// Example :
// Input:
// S = "abcde"
// words = ["a", "bb", "acd", "ace"]
// Output: 3
// Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
// Note:
//
// All words in words and S will only consists of lowercase letters.
// The length of S will be in the range of [1, 50000].
// The length of words will be in the range of [1, 5000].
// The length of words[i] will be in the range of [1, 50].
//
// ***
//
// This question is exactly the same as the follow up question of 392. Is Subsequence.
//
// Note: this question asks about whether word is a *subsequence* of s,
// not if word is a *substring* of s. These two concepts are different.
//
// Frist, traverse through s, for each letter, store the index where it has been seen.
//
// For example:
//
// "acbca"
// 'a': {0, 4}
// 'b': {1}
// 'c': {2, 3}
//
// To find if word is a subsequence of s:
// Initialize previous index to -1, then for each letter in word,
// find (binary search using std::upper_bound) the index of current letter that is greater than previous index.
// If you find such index, set it as the new previous index and continue to next letter in word;
// If you cannot find such index, it means you couldn't find the next letter after current index,
// which means word is not a subsequence of s.

class Solution {
public:
    int numMatchingSubseq(const string& s, vector<string>& words) {
        int subsequenceCount = 0;

        // For each letter, store the index where it has been seen.
        for (int i = 0; i < s.size(); ++i) {
            char2indices[s[i]].push_back(i);
        }

        for (string& word : words) {
            if (_cache.count(word)) {
                subsequenceCount += _cache[word];
            } else {
                subsequenceCount += _isSubsequence(word);
            }
        }

        return subsequenceCount;
    }

private:
    bool _isSubsequence(const string& word) {
        int prevIdx = -1;
        for (char letter : word) {
            auto itr = upper_bound(char2indices[letter].begin(), char2indices[letter].end(), prevIdx);

            if (itr == char2indices[letter].end()) {
                return _cache[word] = false;
            }

            prevIdx = *itr;
        }

        return _cache[word] = true;
    }

    // Cache if word string is a subsequence of s,
    // so we can reuse our result if we see duplicate words.
    unordered_map<string, bool> _cache;

    // Using array as hash map.
    array<vector<int>, 256> char2indices;
};

