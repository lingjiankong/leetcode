// ***
//
// Given a string s and a string t, check if s is subsequence of t.
// You may assume that there is only lower case English letters in both s and t.
// t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of
// the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of
// "abcde" while "aec" is not).
//
// Example 1:
// s = "abc", t = "ahbgdc"
//
// Return true.
//
// Example 2:
// s = "axc", t = "ahbgdc"
//
// Return false.
//
// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has
// its subsequence. In this scenario, how would you change your code?
//
// ***
//
// Note: this question asks about whether s is a subsequence of t,
// NOT if s is a substring of t. These two are different concepts.

bool isSubsequence(string s, string t) {
    if (s.empty()) {
        return true;
    }

    int i = 0, j = 0;
    while (i < s.size() and j < t.size()) {
        if (s[i] == t[j]) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }

    return i == s.size();
}

// Solution to the follow up question (there are many incoming S).
// Read the code and you will understand.
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (!_isInitialized) {
            for (int i = 0; i < t.size(); ++i) {
                char2indices[t[i]].push_back(i);
            }
            _isInitialized = true;
        }

        // Why prevIdx = -1 rather than prevIdx = 0?
        // Because when you are looking for new index, you want to find *itr which needs to be strictly larger than
        // prevIdx. If you initialized prevIdx = 0, then the first *itr must be at least 1 to be valid,
        // which isn't true because the first *itr can be 0.
        int prevIdx = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (!char2indices.count(s[i])) {
                return false;
            }

            auto itr = upper_bound(char2indices[s[i]].begin(), char2indices[s[i]].end(), prevIdx);

            if (itr == char2indices[s[i]].end()) {
                return false;
            }

            prevIdx = *itr;
        }

        return true;
    }

private:
    bool _isInitialized = false;
    unordered_map<char, vector<int>> char2indices;
};
