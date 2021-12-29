// ***
//
// Given two strings s and t, determine if they are both one edit distance apart.
//
// Note:
//
// There are 3 possiblities to satisify one edit distance apart:
//
// Insert a character into s to get t
// Delete a character from s to get t
// Replace a character of s to get t
//
// Example 1:
// Input: s = "ab", t = "acb"
// Output: true
// Explanation: We can insert 'c' into s to get t.
//
// Example 2:
// Input: s = "cab", t = "ad"
// Output: false
// Explanation: We cannot get t from s by only one step.
//
// Example 3:
// Input: s = "1203", t = "1213"
// Output: true
// Explanation: We can replace '0' with '1' to get t.
//
// ***
//
// You should understand the problem just by reading the code.
//
// When two strings are of different lengths:
// Example:
// s: international
// t: interxnational
//
// Iterate all letters in the *shorter* string.
// When we see the difference at i = 5 (s[5] = n, t[5] = x),
// we insert 'x' from t to s at i = 5, and then check if s and t are the same
//
// When two strings are of same length:
// Example:
// s. redpig
// t. reopig
//
// Now s and t has equal length, similar idea as above, replace 'd' in s with
// 'o' in t, and check if s and t are the same

// 1. The better solution is second one. This one just gives you intuition about the problem
bool isOneEditDistance(string s, string t) {
    // Make sure s is the shorter string.
    if (s.size() > t.size()) {
        return isOneEditDistance(t, s);
    }

    // If length of s and t differs more than one, or s and t are exactly the same,
    // then it is not possible for s and t to have exactly one edit distance, return false.
    if (s.size() + 1 < t.size() || s == t) {
        return false;
    }

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != t[i]) {
            if (s.size() == t.size()) {
                s[i] = t[i];
            } else {
                // Insert char t[i] to string s at position i. The second parameter, is the number of times to insert c
                // into the string at position i (i.e., the number of times to repeat the character. If you only want to
                // insert one instance of the character, simply pass it 1
                s.insert(i, 1, t[i]);
            }

            break;
        }
    }

    // (s + t[t.size()-1] == t) checks the edge case when the difference is at the last letter
    // For example,
    // s = "abc"
    // t = "abcd"
    return (s == t) || (s + t.back() == t);
}

// 2. Better solution, without modifying existing string.
bool isOneEditDistance(const string& s, const string& t) {
    // Want s to be the smaller string.
    if (s.size() > t.size()) {
        return isOneEditDistance(t, s);
    }

    if (s.size() + 1 < t.size() || s == t) {
        return false;
    }

    // i traverses string s, j traverses string t.
    int i = 0, j = 0;
    int mismatchCount = 0;

    while (i < s.size() && j < t.size()) {
        if (s[i] != t[j]) {
            if (++mismatchCount > 1) {
                return false;
            }
            if (s.size() + 1 == t.size()) {
                ++j;
                continue;
            }
        }

        ++i, ++j;
    }

    return true;
}
