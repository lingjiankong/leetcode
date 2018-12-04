// ***
//
// Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that
// any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.
// 
// Example 1:
// 
// Input: nums = [1,3], n = 6
// Output: 1 
// Explanation:
// Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
// Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
// Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
// So we only need 1 patch.
// Example 2:
// 
// Input: nums = [1,5,10], n = 20
// Output: 2
// Explanation: The two patches can be [2, 4].
// Example 3:
// 
// Input: nums = [1,2,2], n = 5
// Output: 0
//
// ***
//
// The code is easy, but the thinking process is hard. Once you get the intuition, the problmen is ok.
// The following is edited based on Stephan's post in LeetCode discussion:
//
// Let miss be the smallest sum in [0, n] that we might be missing,
// meaning we already know we can build all sums in [0, miss).
// Then if we have a number num <= miss in the given array,
// we can add it to those smaller sums to build all sums in [0, miss + num).
// If we don't, then we must add such number to the array,
// and it's best to add miss itself, to maximize the reach.
// If you add something smaller than miss, you ends up building only [0, miss + num_smaller_than_miss],
// which is not as efficient as extending it to [0, miss + miss).
// However, you can't add a num larger than miss though, or you will end up with
// [0, miss) + [num_bigger_than_miss, miss + num_bigger_than_miss].
// You'll miss the numbers in between.
//
// Example: Let's say the input is nums = [1, 2, 4, 13, 46] and n = 100.
// We need to ensure that all sums in the range [1,100] are possible.
//
// Using the given numbers 1, 2 and 4, we can already build all sums from 0 to 7, i.e., the range [0, 8),
// but we can't build the sum 8, and the next given number (13) is too large.
// So we insert 8 into the array. Then we can build all sums in [0, 8) + 8 -> [0, 16).
//
// Now, do we need to insert 16 into the array? No!
// Because the next num is 13, which is smaller than 16.
// We can add 13 to all sums [0, 16) we are able to build so far, extending our range to [0, 16) + 13 -> [0, 29).
// And so on. Now, the given 46 is too large to help with sum 29, so we must insert 29 into our array.
// This extends our range to [0, 29) + 29 -> [0, 58). Then 46 becomes useful and expands our range to [0, 58) + 46 -> [0, 104),
// which includes everything in [0, 100], now we're done.
//
// Note: the array given is sorted.
int minPatches(vector<int>& nums, int n)
{

	int i = 0;
	int numOfPatches = 0;

	// Initial miss = 1 because we are sure that we can build all sums in [0, 1).
	// i.e. Initially we can sum up to number 0 by using nothing.
	long miss = 1;

	while (miss <= n)
	{
		// We know previously we can cover all number until miss, i.e. [0, previousMiss)
		// If num[i] <= miss, then our coverage is expanded to [0, previousMiss + nums[i])
		// Therefore, update our new miss to be previousMiss + nums[i]
		if (i < nums.size() && nums[i] <= miss)
		{
			miss += nums[i++];
		}

		// If there's no more number, or if the next number is too big, then we patch miss.
		else
		{
			miss += miss;
			++numOfPatches;
		}
	}

	return numOfPatches;
}
