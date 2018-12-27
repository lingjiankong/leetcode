// ***
//
// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
// 
// Formally the function should:
// 
// Return true if there exists i, j, k
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.
// 
// Example 1:
// Input: [1,2,3,4,5]
// Output: true
//
// Example 2:
// Input: [5,4,3,2,1]
// Output: false
//
// ***
//
// This question is slightly different from 414. Third Maximum Number.
bool increasingTriplet(const vector<int>& nums)
{
	int firstMin = INT_MAX; // Most minimum element
	int secondMin = INT_MAX; // Second most minimum element

	// Note: <= (not <) is important, because we want increasing orders.
	// If we want non-decreasing orders, we can do <
	for (int num : nums)
	{
		if (num <= firstMin)
		{
			// num is the most minimum element seen so far
			firstMin = num;
		}
		else if (num <= secondMin)
		{
			// num is the second most minimum element seen so far
			// If we enter this else if loop, then we are guaranteed that there exists
			// the most minimum element (firstMin) that occurs before num (now secondMin)
			secondMin = num;
		}
		else
		{
			// Same logic, now we are guaranteed that there are two increasing elements which
			// occured before num. We found increasing triplet, simply return true.
			return true;
		}
	}

	return false;
}
