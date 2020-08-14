// ***
// 
// Example 1:
// 
// Input: n = 2
// Output: ["1/2"]
// Explanation: "1/2" is the only unique fraction with a denominator less-than-or-equal-to 2.
// Example 2:
// 
// Input: n = 3
// Output: ["1/2","1/3","2/3"]
// Example 3:
// 
// Input: n = 4
// Output: ["1/2","1/3","1/4","2/3","3/4"]
// Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".
// Example 4:
// 
// Input: n = 1
// Output: []
// 
// ***

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> result;
        for (int j = 2; j <= n; ++j) {
            for (int i = 1; i < j; ++i) {
                if (gcd(i, j) == 1) {
                    result.push_back(to_string(i) + "/" + to_string(j));
                }
            }
        }

        return result;
    }
};
