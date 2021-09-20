// ***
//
// Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and
// is greater in value than n. If no such positive integer exists, return -1.
//
// Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit
// integer, return -1.
//
//
// Example 1:
//
// Input: n = 12
// Output: 21
//
//
// Example 2:
//
// Input: n = 21
// Output: -1
//
// ***

class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.size(), i = len - 1;
        for (; i > 0; --i) {
            if (str[i - 1] < str[i]) {
                break;
            }
        }
        // If the integer has all decreasing digits (e.g. 76543),
        // it is not possible to find a greater integer with the same digits.
        if (i == 0) {
            return -1;
        }

        // Otherwise, find the number to swap with str[i-1].
        for (int j = len - 1; j >= i; --j) {
            if (str[j] > str[i - 1]) {
                swap(str[j], str[i - 1]);
                break;
            }
        }

        sort(str.begin() + i, str.end());
        long long res = stoll(str);
        return res > INT_MAX ? -1 : res;
    }
};
