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

string minWindow(string s, string t) {
    unordered_map<char, int> letterCount;

    for (char c : t) {
        ++letterCount[c];
    }

    int left = 0, count = 0, minLength = INT_MAX;
    string toReturn = "";
    for (int i = 0; i < s.size(); ++i) {
        // Why do you need only ++count when letterCount[s[i]] >= 0?
        // (When count == t.size(), we know all letters in t appear in current sliding window)
        // Suppose T = AABCCC (letterCount = {A: 2, B: 1, C: 3}), S = AAAAAAAABCCCCC. When you traverse S, you see bunch
        // of As. You want the number of As in your sliding window to be at least 2 (the more As the better, of course,
        // but you don't really care about those extra As). So when you first see two As you
        // ++count, but your don't need to ++count as you see more As because you have enough As to match As in T
        if (--letterCount[s[i]] >= 0) {
            ++count;
        }

        // When count == t.size(), all letters in t appear in current sliding window.
        // Therefore you start increasing left pointer and "squeeze" the sliding window from left,
        // until right before count < t.size() (meaning a letter from t will be missing in the current sliding window),
        // that's when you start increasing the right pointer again.
        while (count == t.size()) {
            if (i - left + 1 < minLength) {
                minLength = i - left + 1;
                toReturn = s.substr(left, minLength);
            }

            // If s[left] is a letter not in t, it will not affect count at all,
            // because that letterCounter[s[left]] is never be greater than 0.
            if (++letterCount[s[left]] > 0) {
                --count;
            }

            ++left;
        }
    }

    return toReturn;
}
