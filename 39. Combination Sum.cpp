// ***
//
// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
//
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
//
// ***
//
// See also 77. Combinations.
// Note the difference in for loop in this question and 77. Combinations:
// In this question, when we backtrack, the startIndex = i;
// In 77, when we backtrack, the startIndex = i + 1;
// This is because we are allowed to use same element multiple times in this question,
// but in 77. Combinations, we do not allow using same element multiple times.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> all;

        int startIndex = 0;

        _backtrack(candidates, target, startIndex, current, all);

        return all;
    }

private:
    void _backtrack(vector<int>& candidates, int target, int startIndex, vector<int>& current,
                    vector<vector<int>>& all) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            all.push_back(current);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            current.push_back(candidates[i]);
            _backtrack(candidates, target - candidates[i], i, current, all);
            current.pop_back();
        }
    }
};
