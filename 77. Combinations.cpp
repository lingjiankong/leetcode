// ***
//
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//
// ***

// Solution when the input is vector<int>& nums. Clear to see what's going on.
//
// Combination is just a collection of subset with a particular length. See 78. Subsets.
class Solution {
public:
    vector<vector<int>> combine(vector<int>& nums, int k) {
        vector<int> current;
        vector<vector<int>> all;

        int startIndex = 0;

        _backtrack(nums, k, startIndex, current, all);

        return all;
    }

private:
    void _backtrack(vector<int>& nums, int k, int startIndex, vector<int>& current, vector<vector<int>>& all) {
        if (current.size() == k) {
            all.push_back(current);
            return;
        }

        for (int i = startIndex; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            _backtrack(nums, k, i + 1, current, all);
            current.pop_back();
        }
    }
};

// Solution when the input is n (given by the problem).
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int startNumber = 1;

        vector<int> current;
        vector<vector<int>> all;

        _backtrack(n, k, startNumber, current, all);

        return all;
    }

private:
    void _backtrack(int n, int k, int startNumber, vector<int>& current, vector<vector<int>>& all) {
        if (current.size() == k) {
            all.push_back(current);
            return;
        }

        for (int num = startNumber; num <= n; ++num) {
            current.push_back(num);
            _backtrack(n, k, num + 1, current, all);
            current.pop_back();
        }
    }
};
