// The idea is to store all numbers that stisfy the index requirement
// (the absolute difference between i and j is at most k) in a tree set, like a sliding window,
// then see among these numbers, if there is a number such that nums[i]-t <= nums[i] <= nums[i]+t.
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	// A sliding window of last k elements, use <long> to prevent overflow when nums[i]+t
	set<long> seen;

	for (int i = 0; i < nums.size(); ++i)
	{
		if (i > k)
		{
			seen.erase(nums[i-k-1]);
		}

		// See if we can find a number >= nums[i]-t
		auto it = seen.lower_bound((long)(nums[i]) - (long)(t));

		// If we found a number >= nums[i]-t
		if (it != seen.end())
		{
			// Then check if also that number <= nums[i]+t
			if (*it <= (long)(nums[i]) + (long)(t))
			{
				return true;
			}
		}

		seen.insert(nums[i]);
	}

	return false;
}

// Note:
//
// std::set::lower_bound - returns an iterator pointing to the first element in the range [first, last)
// that is greater *or equal to* value, or last if no such element is found.
//
// std::set::upper_bound - returns an iterator pointing to the first element in the range [first, last)
// that is greater than value, or last if no such element is found.
