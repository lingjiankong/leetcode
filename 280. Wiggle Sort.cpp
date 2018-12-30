// ***
//
// Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
// 
// Example:
// 
// Input: nums = [3,5,2,1,6,4]
// Output: One possible answer is [3,5,1,6,2,4]
//
// ***
//
// The question specifically asks us to sort such that
// nums[0] <= nums[1] >= nums[2] <= nums[3]...
// Therefore, if i is odd, then nums[i] must be a ridge, we want nums[i-1] <= nums[i]
// Likely, if the i is even, then nums[i] must be a valley, we want nums[i-1] >= nums[i]
// So if this condition is not satisfied, we just swap(nums[i-1], nums[i])
// 
// You might ask if we swap(nums[i-1], nums[i]), does previous vector still satifiy the condition.
// It does. When you do the swap the previous condition will be maintained.
// It is hard to explain in word, just look at the example:
//
// 0 1 2 3 4 5
// 3 5 2 1 6 4 <--- We are at index 3, which is odd, we want a ridge, but 2 > 1, so we swap them.
//       ^
//       i
//
// 3 5 1 2 6 4 <--- After swap, all conditions still satisfy (i = 2 is still a valley).
//       ^
//       i
//
// 3 5 1 2 6 4 <--- Now we increment i and process the rest. 
//         ^
//         i
void wiggleSort(vector<int>& nums)
{
	for (int i = 1; i < nums.size(); ++i)
	{
		if (((i & 1) && nums[i-1] > nums[i]) || (!(i & 1) && nums[i-1] < nums[i]))
		{
			swap(nums[i-1], nums[i]);
		}
	}
}
