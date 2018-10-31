// O(n)
bool containsDuplicate(vector<int>& nums)
{
	return nums.size() > unordered_set<int>(nums.cbegin(), nums.cend()).size();
}

// O(nlogn)
bool containsDuplicate2(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	for (int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == nums[i-1])
		{
			return true;
		}
	}
	return false;
}

// O(n)
bool containsDuplicate3(vector<int>& nums)
{
	unordered_set<int> seen;
	for (int num : nums)
	{
		if (seen.find(num) != seen.end())
		{
			return true;
		}
		seen.insert(num);
	}
	return false;
}
