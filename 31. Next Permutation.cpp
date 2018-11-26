// ***
//
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place and use only constant extra memory.
// 
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
//
// ***
//
// There's nothing special in this question. You simply need to memorize it.
// See http://www.cnblogs.com/grandyang/p/4428207.html.
//
//  1　　2　　7　　4　　3　　1
//       i
// (                     )
//       From right to left, find first nums[i] < nums[i+1]
// 
//  1　　2　　7　　4　　3　　1
//       i              j
//           (                )
//                      From right to left, find first nums[j] > nums[i]
//  
//  1　　3　　7　　4　　2　　1
//       ^              ^
//  swap(i,             j)
//  
//  1　　3　　1　　2　　4　　7
//            ^              ^
//    reverse(begin+i+1,   end)
//
void nextPermutation(vector<int>& nums)
{
	for (int i = nums.size() - 2; i >= 0; --i)
	{
		if (nums[i] > nums[i+1])
		{
			for (int j = nums.size() - 1; j > i; --j)
			{
				if (nums[j] > nums[i])
				{
					swap(nums[i], nums[j]);
					reverse(nums.begin() + i + 1, nums.end());
					return;
				}
			}
		}
	}

	// If we did not return above, then the entire nums is in descending order,
	// so we should reverse the entire array and get everything in ascending order.
	reverse(nums.begin(), nums.end());
}
