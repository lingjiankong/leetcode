// ***
//
// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
// 
// Note:
// 
// The solution set must not contain duplicate triplets.
// 
// Example:
// 
// Given array nums = [-1, 0, 1, 2, -1, -4],
// 
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
// ***
//
// See also 167. Two Sum II - Input array is sorted
// This is a generalization of that problem with an added for loop.
// The most important thing in this question is to eliminate possibly duplicate result.
// This question can also ask you whether three number can form a target. In this question, that target is 0.
vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> toReturn;

	sort(nums.begin(), nums.end());

	// A special case if target = 0.
	if (nums.empty() || nums.back() < 0 || nums.front() > 0)
	{
		return {};
	}

	int n = nums.size();
	for (int i = 0; i < n - 2; ++i)
	{
		// A special case if target = 0.
		if (nums[i] > 0)
		{
			break;
		}

		// Skip duplicated element.
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}

		int left = i + 1, right = n - 1;
		while (left < right)
		{
			int sum = nums[i] + nums[left] + nums[right];
			if (sum == 0)
			{
				toReturn.push_back({nums[i], nums[left], nums[right]});
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
			else if (sum < 0)
			{
				++left;
			}
			else
			{
				--right;
			}
		}
	}

	return toReturn;
}
