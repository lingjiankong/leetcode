// ***
//
// Write a function that takes an integer n and return all possible combinations of its factors.
//
// Note:
// - You may assume that n is always positive.
// - Factors should be greater than 1 and less than n.
//
// Example 1:
//
// Input: 1
// Output: []
//
// Example 2:
//
// Input: 37
// Output:[]
//
// Example 3:
//
// Input: 12
// Output:
// [
//   [2, 6],
//   [2, 2, 3],
//   [3, 4]
// ]
//
// Example 4:
//
// Input: 32
// Output:
// [
//   [2, 16],
//   [2, 2, 8],
//   [2, 2, 2, 4],
//   [2, 2, 2, 2, 2],
//   [2, 4, 4],
//   [4, 8]
// ]
//
// ***

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> current;
        vector<vector<int>> all;

        int startNumber = 2;

        _backtrack(n, startNumber, current, all);

        return all;
    }

private:
    void _backtrack(int n, int startNumber, vector<int>& current, vector<vector<int>>& all) {
        if (n == 1 and current.size() > 1) {
            all.push_back(current);
        }

        // Why factor <= n here? Because during recursive call, n might not be the original target so
        // we have to consider this number.
        for (int factor = startNumber; factor <= n; ++factor) {
            if (n % factor == 0) {
                current.push_back(factor);
                _backtrack(n / factor, factor, current, all);
                current.pop_back();
            }
        }
    }
};
