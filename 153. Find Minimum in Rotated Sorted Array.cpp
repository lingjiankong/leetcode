// ***
//
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
// Example 1:
// Input: [3,4,5,1,2]
// Output: 1
//
// Example 2:
// Input: [4,5,6,7,0,1,2]
// Output: 0
//
// ***
//
// The smallest element is the rotation pivot.
// This question is the same as asking you where that rotation pivot is.
int findMin(vector<int>& nums)
{
    int left = 0, right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

		// In this case, the pivot is on the right half of the array
        if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return nums[right];
};
