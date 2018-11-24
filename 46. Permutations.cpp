// See also 47. Permutations II.
// level: Recursive level.
// current: Current permutation.
// used: Numbers in nums which have already been recursively visited before.
// all: All permutations.
class Solution
{

	public:

		vector<vector<int>> permute(vector<int>& nums)
		{
			int level = 0;
			vector<int> current;
			vector<bool> used(nums.size(), false);
			vector<vector<int>> all;

			backtrack(nums, level, current, used, all);

			return all;
		}

	private:

		void backtrack(vector<int>& nums, int level, vector<int>& current, vector<bool>& used, vector<vector<int>>& all)
		{
			if (level == nums.size())
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
				backtrack(nums, level + 1, current, used, all);
				current.pop_back();
				used[i] = false;
			}
		}

};
