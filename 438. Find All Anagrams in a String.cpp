// ***
//
// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than
// 20,100. The order of output does not matter.
//
// Example 1:
//
// Input:
// s: "cbaebabacd" p: "abc"
//
// Output:
// [0, 6]
//
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:
//
// Input:
// s: "abab" p: "ab"
//
// Output:
// [0, 1, 2]
//
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
//
// ***
//
// Almost exactly the same as 567. Permutation in String.

// Maintain a sliding window of size p in s, slide it to the right and check
// if window == need, if so then there's a valid anagram. add index to result.
vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
        return {};
    }

    vector<int> window(256), need(256);
    vector<int> res;

    for (int i = 0; i < p.size(); ++i) {
        ++need[p[i]];
        ++window[s[i]];  // Initial sliding window
    }

    // Check if initial windows match
    if (need == window) {
        res.push_back(0);
    }

    // i is the index of the last element in the *new* window to be moved
    for (int i = p.size(); i < s.size(); ++i) {
        // Move window to the right
        ++window[s[i]];
        --window[s[i - p.size()]];

        if (window == need) {
            // Since i is the index (not the right most bound) of the last element in the window, the beginning index of
            // the window is just i - p.size() + 1
            res.push_back(i - p.size() + 1);
        }
    }

    return res;
}

// labuladong sliding window template.
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;

        for (char c : p) {
            ++need[c];
        }

        int left = 0, right = 0;
        int validCount = 0;
        vector<int> res;

        while (right < s.size()) {
            char c = s[right++];
            if (need.count(c)) {
                ++window[c];
                if (window[c] == need[c]) {
                    ++validCount;
                }
            }

            while (right - left == p.size()) {
                if (validCount == need.size()) {
                    res.push_back(left);
                }

                char c = s[left++];
                if (need.count(c)) {
                    if (window[c] == need[c]) {
                        --validCount;
                    }
                    --window[c];
                }
            }
        }

        return res;
    }
};
