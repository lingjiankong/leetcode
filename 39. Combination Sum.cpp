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
// Note the difference in for loop in this question and 77.
// In this question, when we backtrack, the startIndex = i;
// In 77, when we backtrack, the startNum = num + 1;
// This is because we are allowed to use same element multiple times in this question,
// but in 77. Combinations, we do not allow duplicate numbers to be used.
//
class Solution
{

	public:

		vector<vector<int>> combinationSum(vector<int>& candidates, int target)
		{
			vector<int> currentCombination;
			vector<vector<int>> allCombinations;
			int startIndex = 0;

			backtrack(candidates, target, startIndex, currentCombination, allCombinations);

			return allCombinations;
		}

	private:

		void backtrack(vector<int>& candidates, int target, int startIndex, vector<int>& currentCombination, vector<vector<int>>& allCombinations)
		{
			if (target < 0)
			{
				return;
			}

			if (target == 0)
			{
				allCombinations.push_back(currentCombination);
				return;
			}

			for (int i = startIndex; i < candidates.size(); ++i)
			{
				currentCombination.push_back(candidates[i]);
				backtrack(candidates, target - candidates[i], i, currentCombination, allCombinations);
				currentCombination.pop_back();
			}
		}

};
