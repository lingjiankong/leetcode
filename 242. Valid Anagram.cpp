// ***
//
// Given two strings s and t , write a function to determine if t is an anagram of s.
//
// Example 1:
//
// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:
//
// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.
//
// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?
//
// ***
//
// The idea is the similar to 387. First Unique Character in a String and 383. Ransom Note.

// Cleaner version.
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    vector<int> counts(26, 0);

    for (char c : s) {
        ++counts[c - 'a'];
    }

    for (char c : t) {
        --counts[c - 'a'];
    }

    for (int num : counts) {
        if (num != 0) {
            return false;
        }
    }

    return true;
}

// Quicker version. Only two for loops.
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    vector<int> counts(26, 0);

    for (char c : s) {
        ++counts[c - 'a'];
    }

    for (char c : t) {
        if (--counts[c - 'a'] < 0) {
            return false;
        }
    }

    return true;
}
