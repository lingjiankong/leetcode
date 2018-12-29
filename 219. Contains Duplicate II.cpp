// ***
//
// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that
// nums[i] = nums[j] and the absolute difference between i and j is at most k.
// 
// Example 1:
// Input: nums = [1,2,3,1], k = 3
// Output: true
//
// Example 2:
// Input: nums = [1,0,1,1], k = 1
// Output: true
//
// Example 3:
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
//
// ***
//
// The key idea is to use a sliding window of size k using unordered_set.
// Maintain a set s of size k which contain unique values from nums[i - k] to nums[i - 1],
// if nums[i] is in set s then return true, else update the set.
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	// A sliding window of last k elements
	unordered_set<int> window;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (i > k)
		{
			// You want to compare num[i] with elements in [nums[i-k], nums[i-1]],
			// therefore you erase nums[i - k - 1]
			window.erase(nums[i - k - 1]);
		}

		if (window.count(nums[i]))
		{
			return true;
		}

		window.insert(nums[i]);
	}

	return false;
}

// Using unordered_map.
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	// key: num, value: index
	unordered_map<int, int> seen;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (seen.count(nums[i]))
		{
			if (i - seen[nums[i]] <= k)
			{
				return true;
			}
		}
		seen[nums[i]] = i;
	}

	return false;
}
