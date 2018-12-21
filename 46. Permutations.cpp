// ***
//
// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
// ***
//
// See also 47. Permutations II.
//
// current: Current permutation.
// used: Numbers in nums which have already recursively visited before.
// all: All permutations.
//
class Solution
{

	public:

		vector<vector<int>> permute(vector<int>& nums)
		{
			vector<int> current;
			vector<bool> used(nums.size(), false);
			vector<vector<int>> all;

			backtrack(nums, current, used, all);

			return all;
		}

	private:

		void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& all)
		{
			if (current.size() == nums.size())
			{
				all.push_back(current);
				return;
			}

			for (int i = 0; i < nums.size(); ++i)
			{
				if (used[i])
				{
					continue;
				}

				used[i] = true;
				current.push_back(nums[i]);
				backtrack(nums, current, used, all);
				current.pop_back();
				used[i] = false;
			}
		}

};
