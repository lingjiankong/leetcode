// Using unordered_set.
// The basic idea is to maintain a set s which contain unique values from nums[i - k] to nums[i - 1],
// if nums[i] is in set s then return true, else update the set.
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	// A sliding window of last k elements
	unordered_set<int> seen;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (i > k)
		{
			// You want to compare num[i] with elements in [nums[i-k], nums[i-1]],
			// therefore you erase nums[i-k-1]
			seen.erase(nums[i-k-1]);
		}

		if (seen.find(nums[i]) != seen.end())
		{
			return true;
		}

		seen.insert(nums[i]);
	}

	return false;
}

// Using unordered_map
bool containsNearbyDuplicate2(vector<int>& nums, int k)
{
	// Key: num
	// Value: index
	unordered_map<int, int> seen;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (seen.find(nums[i]) != seen.end())
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
