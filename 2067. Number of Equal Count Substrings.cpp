// ***
//
// You are given a 0-indexed string s consisting of only lowercase English letters, and an integer count. A substring of
// s is said to be an equal count substring if, for each unique letter in the substring, it appears exactly count times
// in the substring.
//
// Return the number of equal count substrings in s.
//
// A substring is a contiguous non-empty sequence of characters within a string.
//
//
// Example 1:
//
// Input: s = "aaabcbbcc", count = 3
// Output: 3
// Explanation:
// The substring that starts at index 0 and ends at index 2 is "aaa".
// The letter 'a' in the substring appears exactly 3 times.
// The substring that starts at index 3 and ends at index 8 is "bcbbcc".
// The letters 'b' and 'c' in the substring appear exactly 3 times.
// The substring that starts at index 0 and ends at index 8 is "aaabcbbcc".
// The letters 'a', 'b', and 'c' in the substring appear exactly 3 times.
//
//
// Example 2:
//
// Input: s = "abcd", count = 2
// Output: 0
// Explanation:
// The number of times each letter appears in s is less than count.
// Therefore, no substrings in s are equal count substrings, so return 0.
//
//
// Example 3:
//
// Input: s = "a", count = 5
// Output: 0
// Explanation:
// The number of times each letter appears in s is less than count.
// Therefore, no substrings in s are equal count substrings, so return 0
//
//
// Constraints:
//
// 1 <= s.length <= 3 * 104
// 1 <= count <= 3 * 104
// s consists only of lowercase English letters.
//
// ***

// See also 3. Longest Substring Without Repeating Characters and 2067. Number of Equal Count Substrings.
// This question is somewhat a combinition of the two.
class Solution {
public:
    int equalCountSubstrings(string s, int count) {
        int res = 0;
        int maxUniq = unordered_set<char>(s.begin(), s.end()).size();

        // Individually find number of equal count substring in s with exactly numUniq unique letters.
        // i.e. there are a total of numUniq unique letters, each letter appears exactly count time.
        for (int numUniq = 1; numUniq <= maxUniq; ++numUniq) {
            unordered_map<char, int> window;  // letter to freq
            int validCount = 0;
            int left = 0, right = 0;

            while (right < s.size()) {
                char c = s[right++];
                if (++window[c] == count) {
                    ++validCount;
                }

                while (window.size() > numUniq or window[c] > count) {
                    char c_ = s[left++];
                    if (window[c_] == count) {
                        --validCount;
                    }

                    if (--window[c_] == 0) {
                        window.erase(c_);
                    }
                }

                if (window.size() == numUniq and validCount == numUniq) {
                    ++res;
                }
            }
        }

        return res;
    }
};
