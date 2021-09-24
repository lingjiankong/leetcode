// ***
//
// Given a *sorted* array nums, remove the duplicates in-place such that duplicates appeared at most twice and return
// the new length. Do not allocate extra space for another array, you must do this by modifying the input array in-place
// with O(1) extra memory.
//
// Example 1:
// Given nums = [1,1,1,2,2,3],
// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
// It doesn't matter what you leave beyond the returned length.
//
// Example 2:
// Given nums = [0,0,1,1,1,1,2,3,3],
// Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and
// 3 respectively. It doesn't matter what values are set beyond the returned length.
//
//***
//
// This problem uses the same logic as
// 26. Remove Duplicates from Sorted Array. See that problem for intuition.

int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) {
        return nums.size();
    }

    // All elements to the left of dupStart i.e. [0, dupStart) are guaranteed to contain at most TWO duplicates.
    int dupStart = 2;

    for (int i = 2; i < nums.size(); ++i) {
        // Put all non-triple-duplicate elements to the left of dupStart.
        if (nums[i] != nums[dupStart - 2]) {
            swap(nums[i], nums[dupStart++]);
        }
    }

    return dupStart;
}
