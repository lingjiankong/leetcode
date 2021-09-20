// ***
//
// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
//
// Example 1:
// Input: "aba"
// Output: True
// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
//
// ***
//
// Maintain two pointers left and right, move them toward the center.
// If you see s[l] != s[r], then, to satisfy the problem requirement (by deleting either one makes s a palindrom),
// it means either substring s[l+1, r] (i.e. by deleting s[l]), or substring s[l, r-1] (i.e. by deleting s[r]), is a
// palindrom. If neither of those are palindrom, then it does not satisfy the problem requirement.

class Solution {
public:
    bool validPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                return (isPalindrom(s, l + 1, r) or isPalindrom(s, l, r - 1));
            } else {
                ++l, --r;
            }
        }

        return true;
    }

private:
    bool isPalindrom(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }

        return true;
    }
};
