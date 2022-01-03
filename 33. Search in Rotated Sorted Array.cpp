// ***
//
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
// Example 2:
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//
// ***
//
// Note that you do not have any duplicate element in this question.
// See also 81. Search in Rotated Sorted Array II, where you might have duplicate elements.
// Although you do not know where the pivot point is, either left half or right half of the array must be sorted.
//
// For these kinds of binary search questions which
//
// 1. You need to take the index of left and right
// i.e. left and right serve as indexes, not bounds: nums[left], nums[right]
// -> Then you should initialize left = 0 and right = nums.size() - 1 (not nums.size()), because you can't take index on
// nums when i = nums.size().
//
// 2. You are finding an element which MIGHT NOT be in the array (which you need to return -1), OR
// You don't know what element to find (for example, finding peak, see 852. Peak Index in a Mountain Array)
// -> Then the condition should be while (left <= right) (instead of while (left < right)).
// Otherwise if nums has size 1 then the while loop will simply not execute.
//
// See also 153. Find Minimum in Rotated Sorted Array. In that question, the minimum element is guaranteed to exist
// (which is just the pivot), so the condition in that question is while (left < right) because even if the size of nums
// is just 1, we still return nums[right]

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // if there's duplicate in the array (not required for this question)
        if (nums[mid] == nums[right]) {
            --right;
        }
        // Right half is sorted.
        else if (nums[mid] < nums[right]) {
            // Target is in this sorted right half of the array.
            if (nums[mid] < target and target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // Left half is sorted.
        else if (nums[mid] > nums[right]) {
            // Target is in this sorted left half of the array.
            if (nums[left] <= target and target < nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }

    return -1;
}
