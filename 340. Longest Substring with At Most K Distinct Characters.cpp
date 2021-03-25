// ***
//
// Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct
// characters.
//
// Example 1:
//
// Input: s = "eceba", k = 2
// Output: 3
// Explanation: The substring is "ece" with length 3.
//
// Example 2:
//
// Input: s = "aa", k = 1
// Output: 2
// Explanation: The substring is "aa" with length 2.
//
// ***
//
// Exactly the same as 159. Longest Substring with At Most Two Distinct Characters

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> window;

        int left = 0, right = 0;
        int maxLen = INT_MIN;

        while (right < s.size()) {
            char c = s[right++];
            ++window[c];

            while (window.size() > k) {
                char c = s[left++];
                if (--window[c] == 0) {
                    window.erase(c);
                }
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};

