// ***
//
// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words,
// one of the first string's permutations is the substring of the second string.
//
//
// Example 1:
//
// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
//
//
// Example 2:
//
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
//
//
// Constraints:
//
// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].
//
// ***
//
// Almost exactly the same as 438. Find All Anagrams in a String.

// labuladong sliding window template.
bool checkInclusion(string s1, string s2) {
    vector<int> need(256), window(256);

    for (char c : s1) {
        ++need[c];
    }

    int left = 0, right = 0;
    while (right < s2.size()) {
        char c = s2[right++];
        ++window[c];

        while (right - left == s1.size()) {
            if (need == window) {
                return true;
            }

            char c = s2[left++];
            --window[c];
        }
    }

    return false;
}

// Same idea.
bool checkInclusion(string s1, string s2) {
    unordered_map<char, int> need, window;

    for (char c : s1) {
        ++need[c];
    }

    int left = 0, right = 0;
    int validCount = 0;

    while (right < s2.size()) {
        char c = s2[right++];
        if (need.count(c)) {
            ++window[c];
            if (window[c] == need[c]) {
                ++validCount;
            }
        }

        while (right - left == s1.size()) {
            if (validCount == need.size()) {
                return true;
            }

            char c = s2[left++];
            if (need.count(c)) {
                if (window[c] == need[c]) {
                    --validCount;
                }
                --window[c];
            }
        }
    }

    return false;
}
