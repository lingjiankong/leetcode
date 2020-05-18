// ***
//
// Given an unsorted integer array, find the smallest missing positive integer.
//
// Example 1:
// Input: [1,2,0]
// Output: 3
//
// Example 2:
// Input: [3,4,-1,1]
// Output: 2
//
// Example 3:
// Input: [7,8,9,11,12]
// Output: 1
//
// Your algorithm should run in O(n) time and uses constant extra space.
//
// ***
//
// Easiest solution to this question is to use a HashSet to store values seen, but it is not Space O(1).
//
// The idea of the question is to put positive elements in their corresponding spots.
// i.e. Put 1 at nums[0], 2 at nums[1] ... nums[i] at nums[nums[i]-1]
// We don't care about elements that are non positive and elements that are larger than nums.size(),
// because they can't be the first missing postive.
//
// Example:
//
// Given (sorted for convenience) [-99, -4, 0, 1, 2, 4, 5, 6, 100, 230]
//
// Index:
// [0 1 2 3 4 5 6 7]
// At position 2, we should get 3, but we didn't, therefore, first missing positive is 3
// [1 2 ? 4 5 6 ? ?]
//
int firstMissingPositive(vector<int>& nums) {
    if (nums.empty()) {
        return 1;
    }

    for (int i = 0; i < nums.size(); ++i) {
        // If 0 < nums[i] < nums.size(), we want to put nums[i] at the place it belongs to (i.e. nums[nums[i]-1])
        // After swap(nums[i], nums[nums[i]-1]), nums[nums[i]-1] has the correct value (i.e. nums[i]),
        // but the new nums[i] might still be incorrect, so we must have WHILE loop here instead of an IF statement.
        // For example, if we have [3, 8, 4, -1], when i = 0, num[0] = 3, we swap nums[0] with nums[3-1]
        // and get [4, 8, 3, -1]. Now, nums[2] = 3, which is correct. However, nums[0] = 4, if we were using an if loop,
        // nums[0] still has the wrong value, hence, we must now swap nums[0] with nums[4-1] and get [-1, 8, 3, 4].
        while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < nums.size(); ++i) {
        // e.g. In [1, -1, 3, 4], -1 is not 2, then 2 is the first missing positive
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    return nums.size() + 1;
}
