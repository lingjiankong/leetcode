// ***
//
// Given a set of distinct integers, nums, return all possible subsets (the power set).
// Note: The solution set must not contain duplicate subsets.
// 
// Example:
// 
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
// 
// ***
//
// See also 77. Combinations. Note the difference when to push current to all.
//
class Solution
{

	public:

		vector<vector<int>> subsets(vector<int>& nums)
		{
			vector<int> current;
			vector<vector<int>> all;

			int startIndex = 0;

			backtrack(nums, startIndex, current, all);

			return all;
		}
	
	private:

		void backtrack(vector<int>& nums, int startIndex, vector<int>& current, vector<vector<int>>& all)
		{
			all.push_back(current);

			for (int i = startIndex; i < nums.size(); ++i)
			{
				current.push_back(nums[i]);
				backtrack(nums, i + 1, current, all);
				current.pop_back();
			}
		}

};
