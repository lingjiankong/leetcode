// ***
//
// Given a string num that contains only digits and an integer target, return all possibilities to insert the binary
// operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target
// value.
//
// Note that operands in the returned expressions should not contain leading zeros.
//
//
// Example 1:
//
// Input: num = "123", target = 6
// Output: ["1*2*3","1+2+3"]
// Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
//
//
// Example 2:
//
// Input: num = "232", target = 8
// Output: ["2*3+2","2+3*2"]
// Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
//
//
// Example 3:
//
// Input: num = "105", target = 5
// Output: ["1*0+5","10-5"]
// Explanation: Both "1*0+5" and "10-5" evaluate to 5.
// Note that "1-05" is not a valid expression because the 5 has a leading zero.
//
//
// Example 4:
//
// Input: num = "00", target = 0
// Output: ["0*0","0+0","0-0"]
// Explanation: "0*0", "0+0", and "0-0" all evaluate to 0.
// Note that "00" is not a valid expression because the 0 has a leading zero.
//
//
// Example 5:
//
// Input: num = "3456237490", target = 9191
// Output: []
// Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
//
//
// Constraints:
//
// 1 <= num.length <= 10
// num consists of only digits.
// -2^31 <= target <= 2^31 - 1
//
// ***

// https://leetcode.com/problems/expression-add-operators/discuss/572099/C%2B%2BJavaPython-Backtracking-and-Evaluate-on-the-fly-Clean-and-Concise
//
// We use backtracking to generate all possible expressions by adding +, -, * to between the digits of s string.
//
// There is no priority since there are no parentheses ( and ) in our s string. There are total 3 operators:
//
// + operator: newResult = resSoFar + num
// - operator: newResult = resSoFar - num.
// * operator: We need to keep the prevNum, so newResult = resSoFar - prevNum + prevNum * num.
//
//
//
// The key idea here is to keep track of previous number (prevNum), so when you are applying * operator,
// You can calcualte the new result (new resSoFar). Note that you can only do this since there is no parenthesis.
class Solution {
public:
    vector<string> addOperators(string s, int target) {
        this->s = s;
        this->target = target;
        backtrack(0, "", 0, 0);
        return all;
    }

private:
    void backtrack(int startIndex, string current, long resSoFar, long prevNum) {
        if (startIndex == s.size()) {
            if (resSoFar == target) {
                all.push_back(current);
            }
            return;
        }

        string numStr;
        long num = 0;
        for (int i = startIndex; i < s.size(); ++i) {
            if (i > startIndex and s[startIndex] == '0') {
                break;  // Skip leading zero number
            }

            numStr += s[i];
            num = num * 10 + s[i] - '0';

            if (startIndex == 0) {
                backtrack(i + 1, numStr, num, num);  // First num, pick it without adding any operator!
            } else {
                backtrack(i + 1, current + "+" + numStr, resSoFar + num, num);
                backtrack(i + 1, current + "-" + numStr, resSoFar - num, -num);

                // Can imagine with example: 1 - 2 * 3, where resSoFar = -1, prevNum = -2 and num = 3
                // new resSoFar = resSoFar - prevNum + prevNum * num = -1 - (-2) + (-2) * 3 = -5
                // new prevNum = prevNum * num = -2 * 3 = -6
                backtrack(i + 1, current + "*" + numStr, resSoFar - prevNum + prevNum * num, prevNum * num);
            }
        }
    }

    vector<string> all;
    string s;
    int target;
};

