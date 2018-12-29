// ***
//
// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
// 
// Note:
// 
// The solution set must not contain duplicate quadruplets.
// 
// Example:
// 
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
// 
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
// ***
//
// See also 15. 3Sum. Same idea. This question just add one more for loop.
//
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> toReturn;

	sort(nums.begin(), nums.end());

	int n = nums.size();
	for (int i = 0; i < n - 3; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}

		for (int j = i + 1; j < n - 2; ++j)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
			{
				continue;
			}

			int left = j + 1, right = n - 1;
			while (left < right)
			{
				int sum = nums[i] + nums[j] + nums[left] + nums[right];
				if (sum == target)
				{
					toReturn.push_back({nums[i], nums[j], nums[left], nums[right]});
					while (left < right && nums[left] == nums[left + 1])
					{
						++left;
					}
					while (left < right && nums[right] == nums[right - 1])
					{
						--right;
					}
					++left; --right;
				}
				else if (sum < target)
				{
					++left;
				}
				else
				{
					--right;
				}
			}
		}
	}

	return toReturn;
}
