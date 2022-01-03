// ***
//
// Given an integer array, your task is to find all the different possible increasing subsequences of the given array,
// and the length of an increasing subsequence should be at least 2.
//
// Example:
//
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7, 7], [4, 7, 7]]
//
// Constraints:
//
// The length of the given array will not exceed 15.
// The range of integer in the given array is [-100,100].
// The given array may contain duplicates, and two equal integers should also be considered as a special case of
// increasing sequence.
//
// ***
//
// You cannot eliminate duplicate elements by sorting the array and doing what you did in 90. Subsets II.
// The array sequence in this problem must be fixed because you are finding increasing subsequences within it.
// Use "set<vector<int>> all" instead of "vector<vector<int>> all" to remove duplicates
// (can't use unordered_set since vector<int> is not hashable)

class Solution {
public:
    vector<vector<int>> findSubsequences(const vector<int>& nums) {
        vector<int> current;
        set<vector<int>> all;

        int startIndex = 0;

        _backtrack(nums, startIndex, current, all);

        return vector<vector<int>>(all.begin(), all.end());
    }

private:
    void _backtrack(const vector<int>& nums, int startIndex, vector<int> current, set<vector<int>>& all) {
        if (current.size() >= 2) {
            all.insert(current);
        }

        for (int i = startIndex; i < nums.size(); ++i) {
            if (!current.empty() and nums[i] < current.back()) {
                continue;
            }

            current.push_back(nums[i]);
            _backtrack(nums, i + 1, current, all);
            current.pop_back();
        }
    }
};
