// ***
//
// Given a string s that consists of only uppercase English letters, you can perform at most k operations on that
// string. In one operation, you can choose any character of the string and change it to any other uppercase English
// character.
//
// Find the length of the longest sub-string containing all repeating letters you can get after performing the above
// operations.
//
// Note:
// Both the string's length and k will not exceed 104.
//
// Example 1:
//
// Input:
// s = "ABAB", k = 2
//
// Output:
// 4
//
// Explanation:
// Replace the two 'A's with two 'B's or vice versa.
//
//
// Example 2:
//
// Input:
// s = "AABABBA", k = 1
//
// Output:
// 4
//
// Explanation:
// Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4
//
// ***
//
// This question is similar to 340. Longest Substring with At Most K Distinct Characters.

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> window(26, 0);

        // the char which appears the most in current window and its count
        char maxFreqChar;
        int maxFreqCount = 0;

        int left = 0, right = 0;
        int maxLen = 0;

        while (right < s.size()) {
            char c = s[right++];
            ++window[c - 'A'];

            // needs >= here to have the most up-to-date char (to have correct deletion)
            if (window[c - 'A'] >= maxFreqCount) {
                maxFreqCount = window[c - 'A'];
                maxFreqChar = c;
            }

            while (right - left - maxFreqCount > k) {
                char c = s[left++];
                --window[c - 'A'];

                if (maxFreqChar == c) {
                    maxFreqCount -= 1;
                }
            }

            maxLen = max(maxLen, right - left);
        }

        return maxLen;
    }
};
