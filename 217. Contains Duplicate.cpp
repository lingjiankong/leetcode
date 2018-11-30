// ***
//
// Given an array of integers, find if the array contains any duplicates.
// 
// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
// 
// Example 1:
// Input: [1,2,3,1]
// Output: true
// 
// Example 2:
// Input: [1,2,3,4]
// Output: false
// 
// Example 3:
// Input: [1,1,1,3,3,4,3,2,4,2]
// Output: true
//
// ***
//
// O(n)
bool containsDuplicate(vector<int>& nums)
{
	return nums.size() > unordered_set<int>(nums.cbegin(), nums.cend()).size();
}

// O(nlogn)
bool containsDuplicate(vector<int>& nums)
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
bool containsDuplicate(vector<int>& nums)
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
