// ***
//
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
// ***
//
// See also 46. Permutations, and compare their difference.
//
// In this question, we need to check if the number is a duplicate, AND
// if the number is a duplicate, whether the duplicated number has been used before at current recursive level.
// If so then we shall skip this duplicate number.
class Solution
{

	public:

		vector<vector<int>> permuteUnique(vector<int>& nums)
		{
			sort(nums.begin(), nums.end());
			
			int level = 0;
			vector<int> current;
			vector<bool> used(nums.size(), false);
			vector<vector<int>> all;
			
			dfs(nums, level, current, used, all);

			return all;
		}

	private:

		void dfs(vector<int>& nums, int level, vector<int>& current, vector<bool>& used, vector<vector<int>>& all)
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

				if (i > 0 && nums[i] == nums[i-1] && used[i-1])
				{
					continue; 
				}

				used[i] = true;
				current.push_back(nums[i]);
				dfs(nums, level + 1, current, used, all);
				current.pop_back();
				used[i] = false;
			}
		}

};
