// ***
//
// Given a string s of '(' , ')' and lowercase English characters.
//
// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting
// parentheses string is valid and return any valid string.
//
// Formally, a parentheses string is valid if and only if:
//
// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
//
//
// Example 1:
//
// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
// Example 2:
//
// Input: s = "a)b(c)d"
// Output: "ab(c)d"
// Example 3:
//
// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.
// Example 4:
//
// Input: s = "(a(b(c)d)"
// Output: "a(b(c)d)"
//
//
// Constraints:
//
// 1 <= s.length <= 10^5
// s[i] is one of  '(' , ')' and lowercase English letters.
//
// ***
//
// Intuition:
// To make the string valid with minimum removals, we need to get rid of all parentheses that do not have a matching
// pair.
//
// Push char index into the stack when we see '('.
// Pop from the stack when we see ')'.
//
// If the stack is empty, then we have ')' without the pair, and it needs to be removed.
// In the end, the stack will contain indexes of '(' without the pair, if any. We need to remove all of them too.
//
// We mark parentheses to be removed with '*', and erase all of them in the end.

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> parenStack;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                parenStack.push(i);
            }
            if (s[i] == ')') {
                if (!parenStack.empty()) {
                    parenStack.pop();
                } else {
                    s[i] = '*';
                }
            }
        }

        while (!parenStack.empty()) {
            s[parenStack.top()] = '*';
            parenStack.pop();
        }

        // Note std::remove transforms the range [first, last) into a range with all the elements that compare equal to
        // val removed, and returns an iterator to the new end of that range.
        s.erase(remove(s.begin(), s.end(), '*'), s.end());

        return s;
    }
};
