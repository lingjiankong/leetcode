// ***
//
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target
// value. Your algorithm's runtime complexity must be in the order of O(log n). If the target is not found in the array,
// return [-1, -1].
//
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//
// ***

// Use std::lower_bound() to calculate the first position of the element;
// Use std::upper_bound() to calculate the last position of the element:
vector<int> searchRange(vector<int>& nums, int target) {
    // std::lower_bound on target
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    int leftIndex = right;

    if (leftIndex == nums.size() or nums[leftIndex] != target) {
        return {-1, -1};
    }

    // std::upper_bound on target
    left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    int rightIndex = right - 1;

    return {leftIndex, rightIndex};
}
