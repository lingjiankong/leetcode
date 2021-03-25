// ***
//
// Given a string, find the length of the longest substring without repeating characters.
//
// Example 1:
//
// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
//
// Example 2:
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
// Example 3:
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
// ***

// labuladong sliding window template
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;

    int left = 0, right = 0;
    int maxLen = INT_MIN;

    while (right < s.size()) {
        char c = s[right++];
        ++window[c];

        while (window[c] > 1) {
            char c = s[left++];
            --window[c];
        }

        maxLen = max(maxLen, right - left);
    }

    return maxLen;
}

