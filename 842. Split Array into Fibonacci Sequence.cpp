// ***
//
// You are given a string of digits num, such as "123456579". We can split it into a Fibonacci-like sequence [123, 456,
// 579].
//
// Formally, a Fibonacci-like sequence is a list f of non-negative integers such that:
//
// 0 <= f[i] < 2^31, (that is, each integer fits in a 32-bit signed integer type),
// f.length >= 3, and
// f[i] + f[i + 1] == f[i + 2] for all 0 <= i < f.length - 2.
// Note that when splitting the string into pieces, each piece must not have extra leading zeroes, except if the piece
// is the number 0 itself.
//
// Return any Fibonacci-like sequence split from num, or return [] if it cannot be done.
//
//
// Example 1:
//
// Input: num = "123456579"
// Output: [123,456,579]
//
//
// Example 2:
//
// Input: num = "11235813"
// Output: [1,1,2,3,5,8,13]
//
//
// Example 3:
//
// Input: num = "112358130"
// Output: []
// Explanation: The task is impossible.
//
//
// Example 4:
//
// Input: num = "0123"
// Output: []
// Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not valid.
//
//
// Example 5:
//
// Input: num = "1101111"
// Output: [11,0,11,11]
// Explanation: The output [11, 0, 11, 11] would also be accepted.
//
//
// Constraints:
//
// 1 <= num.length <= 200
// num contains only digits.
//
// ***

class Solution {
public:
    vector<int> splitIntoFibonacci(string s) {
        vector<int> cur;
        vector<vector<int>> all;
        _backtrack(s, cur, all);

        return all.empty() ? vector<int>() : all[0];
    }

private:
    void _backtrack(string s, vector<int>& cur, vector<vector<int>>& all) {
        if (s.empty()) {
            if (cur.size() >= 3) {
                all.push_back(cur);  // problem requires seq len to be at least 3.
            }
            return;
        }

        for (int i = 1; i <= s.size(); ++i) {
            string numStr = s.substr(0, i);

            // cannot have leading 0
            if (numStr.size() > 1 and numStr[0] == '0') {
                break;
            }

            // numStr must fit into 10 bits, otherwise it will overflow when you convert to integral type.
            if (numStr.size() > 10) {
                break;
            }

            // numInt must be less that INT_MAX (given by the problem)
            long numInt = stol(numStr);
            if (numInt > INT_MAX) {
                break;
            }

            // Continue backtracking when:
            // first two numbers in a fib seq can be anything, OR
            // current number is the sum of previous two numbers in cur.
            if (cur.size() < 2 or (numInt == (long)cur[cur.size() - 1] + (long)cur[cur.size() - 2])) {
                cur.push_back(numInt);
                _backtrack(s.substr(i), cur, all);
                cur.pop_back();
            }
        }
    }
};

