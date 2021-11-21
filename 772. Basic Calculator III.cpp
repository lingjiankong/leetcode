// ***
//
// Implement a basic calculator to evaluate a simple expression string.
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers
// and empty spaces . The expression string contains only non-negative integers, +, -, *, / operators , open ( and
// closing parentheses ) and empty spaces . The integer division should truncate toward zero. You may assume that the
// given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].
//
// Some examples:
// "1 + 1" = 2
// " 6-4 / 2 " = 4
// "2*(5+5*2)/3+(6/2+8)" = 21
// "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
//
// Note: Do not use the eval built-in library function.
//
// ***
//
// See comments.
class Solution {
public:
    int calculate(string str) {
        stack<int> s;

        // Initialize the dummy operator as "+"
        char op = '+';
        int num = 0;

        for (int i = 0; i < str.size(); ++i) {
            char c = str[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '(') {
                int iOpen = i, iClose;  // Open and close index of parentheses pair
                int count = 0;
                for (; i < str.size(); ++i) {
                    if (str[i] == '(') {
                        ++count;
                    }
                    if (str[i] == ')') {
                        --count;
                    }
                    if (count == 0) {
                        iClose = i;
                        break;
                    }
                }
                // Recusively deal with calculations inside parenthesis.
                // iOpen is the index of '(' and i is now the index of ')'.
                // Everything inside parenthesis is now num.
                num = calculate(str.substr(iOpen + 1, iClose - iOpen - 1));
            }

            // Here 'c' is the *current* operator at str[i], 'op' is the *last* operator you've seen.
            // This is basically saying that if you see a new operator, this new operator acts like a break point,
            // and you should perform the operation specified by the last seen operator (op).
            // if op is + or -, push num to the top of the stack.
            // if op is * or /, the top of the stack becomes "stack.top() op num".
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

                // Update op, reset num.
                op = c;
                num = 0;
            }
        }

        // Sum over all numbers in stack
        int res = 0;
        while (not s.empty()) {
            res += s.top();
            s.pop();
        }
        return res;
    }
};
