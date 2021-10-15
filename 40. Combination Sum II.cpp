// ***
//
// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sums to target.
// Each number in candidates may only be used once in the combination.
//
// Example:
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
// ***
//
// In this question, we cannot use the same element multiple times,
// and we are no longer guaranteed that we have all unique elements like in 39. Combination Sum,
// so we must sort the array. This question is pretty much the same as 39. Combination Sum, with two differences:
//
// 1. In this question, startIndex in the backtracking function is i + 1 (i.e. next element) instead of i, this prevent
// multiple use of the same element.
// 2. Sort the input array and check if (i > startIndex && candidates[i-1] == candidates[i]), this prevent duplicate
// result, for example, [1, 7] and [7, 1] will only appear once.
//
// Note: it is if i > startIndex, NOT if i > 0.
//
// Also, because candidates are sorted, "if (target < 0)" can be put inside the for loop: i.e. check if (candidates[i] >
// target) so we will break the for loop if target is less that candidates[i], so we don't have to unnecessarily
// traverse all of candidates.

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> all;

        int startIndex = 0;

        sort(candidates.begin(), candidates.end());

        _backtrack(candidates, target, startIndex, current, all);

        return all;
    }

private:
    void _backtrack(vector<int>& candidates, int target, int startIndex, vector<int>& current,
                    vector<vector<int>>& all) {
        if (target == 0) {
            all.push_back(current);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                break;
            }

            // You can not use the same number on the same level. However, on next level you may use it.
            // For example, candidates = [1, 1, 1, 1, 9], target = 10, you only want one [1, 9], where 1 is the first 1.
            if (i > startIndex && candidates[i - 1] == candidates[i]) {
                continue;
            }

            current.push_back(candidates[i]);
            _backtrack(candidates, target - candidates[i], i + 1, current, all);
            current.pop_back();
        }
    }
};

