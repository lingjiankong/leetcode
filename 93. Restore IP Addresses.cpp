// ***
//
// Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can
// return them in any order.
//
// A valid IP address consists of exactly four integers, each integer is between 0 and 255, separated by single dots and
// cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses and "0.011.255.245",
// "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
//
//
// Example 1:
//
// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
//
//
// Example 2:
//
// Input: s = "0000"
// Output: ["0.0.0.0"]
//
//
// Example 3:
//
// Input: s = "1111"
// Output: ["1.1.1.1"]
//
//
// Example 4:
//
// Input: s = "010010"
// Output: ["0.10.0.10","0.100.1.0"]
//
//
// Example 5:
//
// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
//
//
// Constraints:
//
// 0 <= s.length <= 3000
// s consists of digits only.
//
// ***

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> all;
        string cur;
        backtrack(s, 4, cur, all);
        return all;
    }

private:
    void backtrack(string s, int k, string cur, vector<string> &all) {
        if (k == 0) {
            if (s.empty()) {
                all.push_back(cur);
            }
            return;
        }

        for (int i = 1; i <= 3; ++i) {
            if (s.size() >= i and isValid(s.substr(0, i))) {
                if (k == 1) {  // Last part of ip. No need for '.'
                    backtrack(s.substr(i), k - 1, cur + s.substr(0, i), all);
                } else {
                    backtrack(s.substr(i), k - 1, cur + s.substr(0, i) + ".", all);
                }
            }
        }
    }

    bool isValid(string s) {
        if (s.empty() or s.size() > 3 or (s.size() > 1 and s[0] == '0')) {
            return false;
        }
        int all = stoi(s);
        return 0 <= all and all <= 255;
    }
};
