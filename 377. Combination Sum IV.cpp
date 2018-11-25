// ***
//
// Given an integer array with all positive numbers and no duplicates,
// find the number of possible combinations that add up to a positive integer target.
// Use the same number multiple times is allowed.
//
// Example:
//
// nums = [1, 2, 3]
// target = 4
// 
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// 
// Note that different sequences are counted as different combinations.
// 
// Therefore the output is 7.
//
// ***
//
// This problem should be in fact called something permutation.
// Recursive solution will result in TLE. Need to use dynamic programming.
//
// Meaning of mCache[target] and dp(nums, target):
// Number of combinations that uses nums to sum up to target.
//
// For example, nums = [1, 2, 3], target = 4:
//
// Let's assume dp returns vector<vector<int>> of all possible combinations, then
//
// totalCombinations =
//   {1} x dp([1, 2, 3], 3)
// + {2} x dp([1, 2, 3], 2)
// + {3} x dp([1, 2, 3], 1)
//
// dp[0] = 1 because there is only one way to form target 0: empty vector {}.
// INT_MIN in mCache is just a placeholder to be updated.
//
class Solution
{

	public:

		int combinationSum4(vector<int>& nums, int target)
		{
			mCache = vector<int>(target + 1, INT_MIN);

			mCache[0] = 1;

			return dp(nums, target);
		}
	
	private:

		vector<int> mCache;

		int dp(vector<int>& nums, int target)
		{
			if (target < 0)
			{
				return 0;
			}

			if (mCache[target] != INT_MIN)
			{
				return mCache[target];
			}

			int totalCombinations = 0;
			for (int num : nums)
			{
				totalCombinations += dp(nums, target - num);
			}

			return mCache[target] = totalCombinations;
		}

};
