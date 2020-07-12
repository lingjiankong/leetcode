// ***
//
// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace
// character.
//
// Note that after backspacing an empty text, the text will continue empty.
//
// Example 1:
//
// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:
//
// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:
//
// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:
//
// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:
//
// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// Follow up:
//
// Can you solve it in O(N) time and O(1) space?
//
// ***

// The easiest method is just do a simulation on what's going on w.r.t. each string, O(n) space.
//
// Note that, c == '#' ? s.size() > 0 ? s.pop_back() : void() : s.push_back(c); is equivalent to:
// if (c == '#') {
//     if (s.size() > 0) { s.pop_back(); }
//     else { void(); }
// } else {
//     s.push_back(c);
// }
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s = "", t = "";

        for (char c : S) {
            c == '#' ? s.size() > 0 ? s.pop_back() : void() : s.push_back(c);
        }

        for (char c : T) {
            c == '#' ? t.size() > 0 ? t.pop_back() : void() : t.push_back(c);
        }

        return s == t;
    }
};

// O(1) space.
// Maintain two pointers i and j and traverse both strings *from back to start*.
// count is the number of times we've seen #. While we are seeing # or count > 0, we can skip the previous letter(s)
// (since the letter(s) will be deleted) by decrement the pointer. If current letter is #, then increase count. We only
// compare the last letters on S and T when we do not have any # on the right on both strings.
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = (int)S.size() - 1, j = (int)T.size() - 1, count1 = 0, count2 = 0;

        while (i >= 0 || j >= 0) {
            while (i >= 0 && (S[i] == '#' || count1 > 0)) {
                S[i--] == '#' ? ++count1 : --count1;
            }
            while (j >= 0 && (T[j] == '#' || count2 > 0)) {
                T[j--] == '#' ? ++count2 : --count2;
            }

            // It is possible that i or j becomes negative when the first letter is #.
            if (i < 0 || j < 0) {
                return i == j;
            }
            if (S[i--] != T[j--]) {
                return false;
            }
        }

        return i == j;
    }
};
