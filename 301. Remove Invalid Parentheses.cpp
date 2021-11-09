// ***
//
// Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the
// input string valid.
//
// Return all the possible results. You may return the answer in any order.
//
//
//
// Example 1:
//
// Input: s = "()())()"
// Output: ["(())()","()()()"]
// Example 2:
//
// Input: s = "(a)())()"
// Output: ["(a())()","(a)()()"]
// Example 3:
//
// Input: s = ")("
// Output: [""]
//
//
// Constraints:
//
// 1 <= s.length <= 25
// s consists of lowercase English letters and parentheses '(' and ')'.
// There will be at most 20 parentheses in s.
//
// ***

// BFS the original string and remove parenthesis one by one, until you find a valid string.
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        queue<string> q{{s}};
        unordered_set<string> visited{{s}};

        while (not q.empty()) {
            // Already found min deletions, no need to BFS anymore.
            if (not ans.empty()) {
                break;
            }

            int qSize = q.size();
            while (qSize--) {
                string cur = q.front();
                q.pop();

                // Found goal.
                if (isValid(cur)) {
                    ans.push_back(cur);
                }

                for (int i = 0; i < cur.size(); ++i) {
                    if (cur[i] != '(' and cur[i] != ')') {
                        continue;
                    }

                    string str = cur.substr(0, i) + cur.substr(i + 1);
                    if (not visited.count(str)) {
                        q.push(str);
                        visited.insert(str);
                    }
                }
            }
        }

        return ans;
    }

    bool isValid(string& s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++count;
            } else if (s[i] == ')' and --count < 0) {
                return false;
            }
        }
        return count == 0;
    }
};
