// ***
//
// Given a balanced parentheses string S, compute the score of the string based on the following rule:
//
// () has score 1
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.
//
//
// Example 1:
//
// Input: "()"
// Output: 1
// Example 2:
//
// Input: "(())"
// Output: 2
// Example 3:
//
// Input: "()()"
// Output: 2
// Example 4:
//
// Input: "(()(()))"
// Output: 6
//
// ***

// Using stack.
int scoreOfParentheses(string S) {
    stack<int> scoreStack;
    scoreStack.push(0);
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            scoreStack.push(0);
        } else {
            // Get current score
            int score = scoreStack.top();
            scoreStack.pop();

            // Update current score
            score = scoreStack.top() + max(score * 2, 1);
            scoreStack.pop();

            // Push updated score to stack
            scoreStack.push(score);
        }
    }

    return scoreStack.top();
}

// Approach 2: O(1) space
// We count the number of layers.
// If we meet '(', layer++
// else we meet ')', layer--
//
// If we meet "()", we know the number of layer outside,
// so we can calculate the score res += 1 << layer.
int scoreOfParentheses(string S) {
    int result = 0, layer = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == '(') {
            layer++;
        } else {
            layer--;
        }
        if (S[i] == ')' && S[i - 1] == '(') {
            result += 1 << layer;
        }
    }

    return result;
}
