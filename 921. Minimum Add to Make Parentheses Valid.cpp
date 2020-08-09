// ***
//
// Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any
// positions ) so that the resulting parentheses string is valid.
//
// Formally, a parentheses string is valid if and only if:
//
// It is the empty string, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.
// Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.
//
//
// Example 1:
//
// Input: "())"
// Output: 1
//
// Example 2:
//
// Input: "((("
// Output: 3
//
// Example 3:
//
// Input: "()"
// Output: 0
//
// Example 4:
//
// Input: "()))(("
// Output: 4
//
//
// Note:
//
// S.length <= 1000
// S only consists of '(' and ')' characters.
//
// ***

class Solution {
public:
    int minAddToMakeValid(string S) {
        int leftNeeded = 0, rightNeeded = 0;
        for (char c : S) {
            if (c == '(') {
                // If we see a left parentheses, we need a right parentheses to pair it, therefore ++rightNeeded.
                ++rightNeeded;
            } else if (rightNeeded > 0) {
                // Else if we see a right parentheses, and we are currently in need of some right parentheses (indicated
                // by rightNeeded > 0), then this particular right parentheses that we just saw can pair with some
                // previous left parentheses which needs a right parentheses, therefore --rightNeeded.
                --rightNeeded;
            } else {
                // Otherwise, if we see a right parentheses, but rightNeeded == 0 now meaning no left parentheses to
                // pair this new right parentheses, therefore, ++leftNeeded.
                ++leftNeeded;
            }
        }
        return leftNeeded + rightNeeded;
    }
};
