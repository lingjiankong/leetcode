// ***
//
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is
// valid.
//
// An input string is valid if:
//
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Note that an empty string is also considered valid.
//
// Example 1:
// Input: "()"
// Output: true
//
// Example 2:
// Input: "()[]{}"
// Output: true
//
// Example 3:
// Input: "(]"
// Output: false
//
// Example 4:
// Input: "([)]"
// Output: false
//
// Example 5:
// Input: "{[]}"
// Output: true
//
// ***

bool isValid(string s) {
    stack<char> stack_;

    for (char c : s) {
        if (c == '{' || c == '[' || c == '(') {  // push open parentheses to the stack
            stack_.push(c);
        } else {  // compare close parentheses with the top of the stack
            if (stack_.empty()) {
                return false;
            } else if (c == '}' && stack_.top() != '{') {
                return false;
            } else if (c == ']' && stack_.top() != '[') {
                return false;
            } else if (c == ')' && stack_.top() != '(') {
                return false;
            }

            stack_.pop();  // valid parentheses pair, pop the matching close parentheses.
        }
    }

    return stack_.empty();
}
