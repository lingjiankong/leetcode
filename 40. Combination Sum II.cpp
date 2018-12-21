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
// This question is pretty much the same as 39. Combination Sum, with two differences:
// 1. In this question, startIndex in the backtracking function is i + 1 (i.e. next element) instead of i, this prevent multiple use of the same element.
// 2. Checks if (i > startIndex && candidates[i-1] == candidates[i]), this prevent duplicate result, for example, [1, 7] and [7, 1] will only appear once.
// Note: it is if i > startIndex, NOT if i > 0.
//
// Also, because candidates are sorted, if (target < 0) can be put inside the for loop: i.e. check if (candidates[i] > target) so we will break
// the for loop if target is less that candidates[i], so we don't have to unnecessarily traverse all of candidates.
class Solution
{

    public:

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
        {
            int startIndex = 0;
            vector<int> currentCombination;
            vector<vector<int>> allCombinations;

			sort(candidates.begin(), candidates.end());

            backtrack(candidates, target, startIndex, currentCombination, allCombinations);

            return allCombinations;
        }

    private:

        void backtrack(vector<int>& candidates, int target, int startIndex, vector<int>& currentCombination, vector<vector<int>>& allCombinations)
        {
            if (target == 0)
            {
                allCombinations.push_back(currentCombination);
                return;
            }

            for (int i = startIndex; i < candidates.size(); ++i)
            {
				if (candidates[i] > target)
				{
					break;
				}

				if (i > startIndex && candidates[i - 1] == candidates[i])
				{
					continue;
				}

                currentCombination.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i + 1, currentCombination, allCombinations);
                currentCombination.pop_back();
            }
        }

};

