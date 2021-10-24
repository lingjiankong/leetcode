// ***
//
// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed)
// parentheses substring.
//
// Example 1:
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
// Example 2:
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"
//
// ***

// DP solution.
//
// Definition:
// dp[i]: longest valid parentheses substring ending in s[i-1].
//
// Base condition:
// dp[0] = 0: No parentheses, longest valid parentheses is just 0.
// dp[1] = 0: A single parentheses cannot be valid, longest valid parentheses is just 0.
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> dp(s.size() + 1);

        for (int i = 2; i < dp.size(); ++i) {
            // left is the index of matching parentheses of s[i-1]
            int left = (i - 1) - dp[i - 1] - 1;
            if (left >= 0 and s[left] == '(' and s[i - 1] == ')') {
                // you also add need dp[left] because dp[left] might be something like ((()()()))
                // which can be add to any valid parentheses to make it longer.
                dp[i] = dp[i - 1] + 2 + dp[left];
                res = max(res, dp[i]);
            } else {
                // Otherwise if s[i-1] is an open parenthesis,
                // or if s[left] is a close parenthesis, then
                // you cannot form any valid parentheses substring ending in s[i-1]
                dp[i] = 0;
            }
        }

        return res;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0, start = 0;

        stack<int> leftParen;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                leftParen.push(i);
            } else if (s[i] == ')') {
                // If we see a ')' but the stack is empty, what we have leftParen so far can't be valid,
                // so we reinitialize the new valid to start = i + 1 (next iteration)
                // For example, when i = 0, the first parenthesis you see is ")", leftParen is empty now, and you would
                // reset start to i + 1 => 0 + 1 = 1.
                if (leftParen.empty()) {
                    start = i + 1;
                } else {
                    // If stack becomes empty after popping, from start to i we have valid parenthesis.
                    //
                    //    valid parenthesis
                    //     ---------------
                    // ) ) ( ) ( ( ( ) ) )
                    //     ^             |
                    //     start = 2     |
                    //                   ^
                    //                   i = 9
                    //
                    // in this case, current valid parentheses length is i - start + 1 => 9 - 2 + 1 = 8
                    //
                    // Otherwise if stack is non-empty after popping, then from leftParen.top() to i we have valid
                    // parenthesis.
                    //
                    //   valid parenthesis
                    //     -------------
                    // ) ) ( ( ) ( ( ) )
                    //     ^     ^     ^
                    //     |     |     i = 8
                    //     |     |
                    //     |     this element has been popped
                    //     |
                    //     leftParen.top() = 2
                    //
                    // in this case, current valid parentheses length is i - leftParen.top() => 8 - 2 = 6
                    leftParen.pop();
                    longest = leftParen.empty() ? max(longest, i - start + 1) : max(longest, i - leftParen.top());
                }
            }
        }

        return longest;
    }
};
