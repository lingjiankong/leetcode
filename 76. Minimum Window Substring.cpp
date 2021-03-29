// ***
//
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in
// complexity O(n).
//
// Example:
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:
//
// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
//
// ***

// labuladong sliding window template
string minWindow(string s, string t) {
    unordered_map<char, int> need, window;

    for (char c : t) {
        ++need[c];
    }

    int left = 0, right = 0;
    int validCount = 0;
    int start = 0, minLen = INT_MAX;

    while (right < s.size()) {
        char c = s[right++];
        if (need.count(c)) {
            ++window[c];
            if (window[c] == need[c]) {
                ++validCount;
            }
        }

        while (validCount == need.size()) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
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

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
