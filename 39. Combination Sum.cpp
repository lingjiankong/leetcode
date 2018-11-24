// Note: candidates contains non-duplicate numbers.
//
// See also 77. Combinations.
// Note the difference in for loop in this question and 77.
// In this question, when we backtrack, the startIndex = i;
// In 77, when we backtrack, the startNum = num + 1;
// This is because we are allowed to use same element multiple times in this question,
// but we do not allow duplicate numbers to be used in 77. Combinations.
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
				backtrack(candidates, target-candidates[i], i, currentCombination, allCombinations);
				currentCombination.pop_back();
			}
		}

};
