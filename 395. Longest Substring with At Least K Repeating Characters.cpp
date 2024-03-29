// ***
//
// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each
// character in this substring is greater than or equal to k.
//
// Example 1:
//
// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
//
// Example 2:
//
// Input: s = "ababbc", k = 2
// Output: 5
// Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
//
// ***

// See also 2067. Number of Equal Count Substrings.
class Solution {
public:
    int longestSubstring(string s, int k) {
        int minUniq = 1;
        int maxUniq = unordered_set<char>(s.begin(), s.end()).size();
        int maxLen = 0;

        for (int numUniq = minUniq; numUniq <= maxUniq; ++numUniq) {
            // Find the size of the string with exactly numUniq unique characters,
            // and the frequency of each character is greater than or equal to k.
            unordered_map<char, int> window;
            int left = 0, right = 0;
            int curMaxLen = 0;

            while (right < s.size()) {
                char c = s[right++];
                ++window[c];

                while (window.size() > numUniq) {
                    char c = s[left++];
                    if (--window[c] == 0) {
                        window.erase(c);
                    }
                }

                if (window.size() == numUniq and _allCharFreqGrEqK(window, k)) {
                    curMaxLen = max(curMaxLen, right - left);
                }
            }

            maxLen = max(maxLen, curMaxLen);
        }

        return maxLen;
    }

private:
    bool _allCharFreqGrEqK(const unordered_map<char, int>& window, int k) {
        if (window.empty()) {
            return false;
        }

        for (auto& e : window) {
            if (e.second < k) {
                return false;
            }
        }

        return true;
    }
};
