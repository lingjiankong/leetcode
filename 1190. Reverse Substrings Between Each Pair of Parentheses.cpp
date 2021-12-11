// ***
//
// You are given a string s that consists of lower case English letters and brackets.
// Reverse the strings in each pair of matching parentheses, starting from the innermost one.
// Your result should not contain any brackets.
//
//
// Example 1:
//
// Input: s = "(abcd)"
// Output: "dcba"
//
// Example 2:
//
// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first, then the whole string is reversed.
//
// Example 3:
//
// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
//
// Example 4:
//
// Input: s = "a(bcdefghijkl(mno)p)q"
// Output: "apmnolkjihgfedcbq"
//
// ***

// 直接遍历这个字符串，当遇到字母时，将其加入结果 res，
// 当遇到左括号时，将当前 res 的长度加入一个数组 pos，
// 当遇到右括号时，取出 pos 数组中的最后一个数字，并翻转 res 中该位置到结尾的所有字母，
// 因为这个区间刚好就是当前最内层的字母，这样就能按顺序依次翻转所有括号中的内容，最终返回结果 res 即可
class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> opened;  // length of string until last open parentheses
        string res;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                opened.push_back(res.length());
            } else if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                // Reverse the string in between this parentheses pair.
                reverse(res.begin() + j, res.end());
            } else {
                res += s[i];
            }
        }

        return res;
    }
};
