// To the left of l are all 0's
// To the right of r are all 2's
// In between l and i (inclusive) are all 1's
// We traverse until i == r, so that in between l and r (inclusive) are all 1's.
// 
// left: Tracks the position which all elements to the left are 0. 
// index: Traverse in between left and right
// right: Tracks the position which all elements to the right are 2. 
//
// Example:
//
// 0, 0, 0, 0, 1, 1, 1, 2, 1, 0, 2, 1, 0, 2, 2, 2, 2
//             l                       r
//                   i
// 
// 0, 0, 0, 0, 1, 1, 1, 2, 1, 0, 2, 1, 0, 2, 2, 2, 2
//             l                       r
//                      i
// 
// 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 2, 1, 2, 2, 2, 2, 2
//             l                    r
//                      i
//
// 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 2, 1, 2, 2, 2, 2, 2
//                l                 r
//                         i
//
void sortColors(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	int index = 0;

	// Why do we use while(index<=right) instead of using for (int i = 0; i <= nums.size(); ++i) ?
	// Because you see in the last else if loop (when nums[i]==2), index is not incremented.
	// See the example above. When nums[i] and nums[r] are swapped (second line),
	// nums[i] becomes 0, and it is still NOT in the right position.
	// So there must be another swap between nums[l] and nums[i] (third line).
	// After this swap, we may increment i. That's why we use a while loop instead of a for loop here,
	// because we would like to make sure that nums[i] is in the rigth position before increment i.
	while (index <= right)
	{
		if (nums[index] == 0)
		{
			swap(nums[left++], nums[index++]);
		}
		else if (nums[index] == 1)
		{
			index++;
		}
		else if (nums[index] == 2)
		{
			swap(nums[index], nums[right--]);
		}
	}
}
