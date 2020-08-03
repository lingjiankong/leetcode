// ***
//
// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// 
// Find all strobogrammatic numbers that are of length = n.
// 
// Example:
// 
// Input:  n = 2
// Output: ["11","69","88","96"]
//
// ***
//
// n = 0: none
// n = 1: 0, 1, 8
// n = 2: 11, 69, 88, 96
// n = 3: 101, 609, 808, 906, 111, 619, 818, 916, 181, 689, 888, 986
// n = 4: 1001, 6009, 8008, 9006, 1111, 6119, 8118, 9116, 1691, 6699, 8698, 9696, 1881, 6889, 8888, 9886, 1961, 6969, 8968, 9966
//
// Look at n = 1 and n = 3.
// During n = 3, each number in n = 1 is added with 1...1, 6...9, 8...8, 9...6 on left and right side.
// n = 2 and n = 4 follows the same rule.

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return _find(n, n);
    }

private:
    vector<string> _find(int m, int n) {
        if (m == 0) {
            return {""};
        }

        if (m == 1) {
            return {"0", "1", "8"};
        }

        vector<string> words = _find(m - 2, n);
        vector<string> result;
        for (string word : words) {
            if (m != n) {
                result.push_back("0" + word + "0");
            }
            result.push_back("1" + word + "1");
            result.push_back("6" + word + "9");
            result.push_back("8" + word + "8");
            result.push_back("9" + word + "6");
        }

        return result;
    }
};

