// ***
//
// Implement a basic calculator to evaluate a simple expression string.
// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer
// division should truncate toward zero.
//
// Example 1:
//
// Input: "3+2*2"
// Output: 7
// Example 2:
//
// Input: " 3/2 "
// Output: 1
// Example 3:
//
// Input: " 3+5 / 2 "
// Output: 5
// Note:
//
// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.
//
// ***
//
// This is a simpler version of the question (no parentheses)
// See 772. Basic Calculator III (which has parentheses) for explanation.

class Solution {
public:
    int calculate(string str) {
        stack<int> s;

        char op = '+';
        long num = 0;

        for (int i = 0; i < str.size(); ++i) {
            char c = str[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if (c == '+' or c == '-' or c == '*' or c == '/' or i == str.size() - 1) {
                switch (op) {
                    case '+':
                        s.push(num);
                        break;
                    case '-':
                        s.push(-num);
                        break;
                    case '*':
                        s.top() *= num;
                        break;
                    case '/':
                        s.top() /= num;
                        break;
                }

                op = c;
                num = 0;
            }
        }

        int res = 0;
        while (not s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};

