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
        // Move right boundary of the window to the right.
        char c = s[right++];
        if (need.count(c)) {
            ++window[c];
            if (window[c] == need[c]) {
                ++validCount;
            }
        }

        // Determine if we need to move left bounrdary of the window to the right.
        while (validCount == need.size()) {
            if (right - left < minLen) {
                minLen = right - left;  // [left, right)
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

// Similar idea
string minWindow(string s, string t) {
    unordered_map<char, int> need;

    for (char c : t) {
        ++need[c];
    }

    // [left, right]
    int left = 0, totalMatch = 0;
    int start = 0, minLen = INT_MAX;

    for (int right = 0; right < s.size(); ++right) {
        // Why do you need only ++totalMatch when need[s[right]] >= 0?
        // (When totalMatch == t.size(), we know all letters in t appear in current sliding window)
        // Suppose T = AABCCC (need = {A: 2, B: 1, C: 3}), S = AAAAAAAABCCCCC. When you traverse S, you see
        // bunch of As. You want the number of As in your sliding window to be at least 2 (the more As the better,
        // of course, but you don't really care about those extra As). So when you first see two As you
        // ++totalMatch, but your don't need to ++totalMatch as you see more As because you have enough As to match
        // As in T
        if (--need[s[right]] >= 0) {
            ++totalMatch;
        }

        // When totalMatch == t.size(), all letters in t appear in current sliding window.
        // Therefore you start increasing left pointer and "squeeze" the sliding window from left,
        // until right before totalMatch < t.size() (meaning a letter from t will be missing in the current sliding
        // window), that's when you start increasing the right pointer again.
        while (totalMatch == t.size()) {
            if (right - left + 1 < minLen) {
                start = left;
                minLen = right - left + 1;  // [left, right]
            }

            // If s[left] is a letter not in t, it will not affect totalMatch at all,
            // because that need[s[left]] is never going to be greater than 0.
            if (++need[s[left]] > 0) {
                --totalMatch;
            }

            ++left;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
