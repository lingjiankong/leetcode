// ***
//
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
// You are given a target value to search. If found in the array return true, otherwise return false.
//
// Example 1:
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
//
// Example 2:
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
//
// ***

bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return true;
        }

        if (nums[mid] == nums[right]) {  // seeing duplicate element
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
        // Left half is not sorted.
        else if (nums[mid] > nums[right]) {
            // Target is in the sorted left half of the array.
            if (nums[left] <= target and target < nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }

    return false;
}
