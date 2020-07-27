// ***
//
// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it
// would be if it were inserted in order. You may assume no duplicates in the array.
//
// Example 1:
// Input: [1,3,5,6], 5
// Output: 2
//
// Example 2:
// Input: [1,3,5,6], 2
// Output: 1
//
// Example 3:
// Input: [1,3,5,6], 7
// Output: 4
//
// Example 4:
// Input: [1,3,5,6], 0
// Output: 0
//
// ***

// This is just the implementation of std::lower_bound().
// Returns an iterator pointing to the first element in the range [first, last) that is not less than
// (i.e. greater or equal to) value.
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return right;
}

// Recap: vanilla binary search
// If the question were asking us to find the location of target and return -1 if it is not found, then the code becomes
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return -1;
}
