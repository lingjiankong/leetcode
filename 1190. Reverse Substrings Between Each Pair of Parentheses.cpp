// ***
//
// You are given a string s that consists of lower case English letters and brackets.
// Reverse the strings in each pair of matching parentheses, starting from the innermost one.
// Your result should not contain any brackets.
//
//
// Example 1:
//
// Input: s = "(abcd)"
// Output: "dcba"
//
// Example 2:
//
// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is reversed.
//
// Example 3:
//
// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
//
// Example 4:
//
// Input: s = "a(bcdefghijkl(mno)p)q"
// Output: "apmnolkjihgfedcbq"
//
// ***

class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> opened;
        string result;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                opened.push_back(result.length());
            } else if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                // Reverse the string in between this parentheses pair.
                reverse(result.begin() + j, result.end());
            } else {
                result += s[i];
            }
        }

        return result;
    }
};
