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

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        // left is the left boundary of the resulting substring t
        int length = 0, left = 0;

        // Maintain a hash map of how many times you've seen a particular letter
        unordered_map<char, int> letterCount;
        for (int i = 0; i < s.size(); ++i) {
            ++letterCount[s[i]];
            // Pop elements from the hash map when there are more than to letters
            while (letterCount.size() > 2) {
                if (--letterCount[s[left]] == 0) {
                    letterCount.erase(s[left]);
                }
                ++left;
            }

            // ccaabbb
            //   ^
            //   left
            //       ^
            //       i
            length = max(length, i - left + 1);
        }

        return length;
    }
};
