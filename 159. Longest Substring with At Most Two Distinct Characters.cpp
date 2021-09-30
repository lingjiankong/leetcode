// ***
//
// Given a string s , find the length of the longest substring t that contains at most 2 distinct characters.
//
// Example 1:
//
// Input: "eceba"
// Output: 3
// Explanation: t is "ece" which its length is 3.
// Example 2:
//
// Input: "ccaabbb"
// Output: 5
// Explanation: t is "aabbb" which its length is 5.
//
// ***
//
// Exactly the same as 340. Longest Substring with At Most K Distinct Characters

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> window;

        int left = 0, right = 0;
        int maxLen = 0;

        while (right < s.size()) {
            char c = s[right++];
            ++window[c];

            while (window.size() > 2) {
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

