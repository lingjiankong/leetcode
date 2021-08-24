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

class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0, start = 0;

        stack<int> seen;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                seen.push(i);
            } else if (s[i] == ')') {
                // If we see a ')' but the stack is empty, what we have seen so far can't be valid,
                // so we reinitialize the new valid to start = i + 1 (next iteration)
                // For example, when i = 0, the first parenthesis you see is ")", seen is empty now, and you would
                // reset start to i + 1 => 0 + 1 = 1.
                if (seen.empty()) {
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
                    // Otherwise if stack is non-empty after popping, then from seen.top() to i we have valid
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
                    //     seen.top() = 2
                    //
                    // in this case, current valid parentheses length is i - seen.top() => 8 - 2 = 6
                    seen.pop();
                    longest = seen.empty() ? max(longest, i - start + 1) : max(longest, i - seen.top());
                }
            }
        }

        return longest;
    }
};

// DP solution. Should be intuitive.
//
// Definition:
// dp[i]: longest valid parentheses substring ending in s[i-1].
//
// Base condition:
// dp[0] = 0: A single parentheses cannot be valid.
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> dp(s.size() + 1);

        for (int i = 1; i < dp.size(); ++i) {
            // j is the index of matching parentheses of s[i-1]
            // dp[i] == dp[i-1] + 2 only if s[i-1] == ')' and s[j] == '('
            int j = i - dp[i - 1] - 2;
            if (s[i - 1] == '(' or j < 0 or s[j] == ')') {
                dp[i] = 0;
            } else {
                // Case s[j] == '(' and s[i-1] = ')'
                // Note: you need to add dp[j] for scenarios like this:
                // dp[j] + '(' + dp[j-1] + ')'
                // ()(())          ((()()
                dp[i] = dp[i - 1] + 2 + dp[j];
                res = max(res, dp[i]);
            }
        }

        return res;
    }
};
