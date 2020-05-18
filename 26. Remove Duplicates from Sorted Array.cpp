// ***
//
// Given a *sorted* array nums, remove the duplicates in-place such that each element appear only once and return the new
// length. Do not allocate extra space for another array, you must do this by modifying the input array in-place with
// O(1) extra memory.
//
// Example 1:
// Given nums = [1,1,2],
// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
// It doesn't matter what you leave beyond the returned length.
//
// Example 2:
// Given nums = [0,0,1,1,1,2,2,3,3,4],
// Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4
// respectively.
//
// It doesn't matter what values are set beyond the returned length.
//
// ***
//
// See 27. Remove Element and 283. Move Zeros. The idea is the same.
//
int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 1) {
        return nums.size();
    }

    // Because nums is a sorted array, nums[0] just stays at where it is, therefore dupStart starts at 1.
    // dupStart is the position of first occurance of possible duplicate elements, i.e. it is possible that
    // nums[dupStart] = nums[dupStart-1]. All elements to the left of dupStart i.e. [0, dupStart) are guaranteed to
    // contain no duplicate.
    int dupStart = 1;

    for (int i = 1; i < nums.size(); ++i) {
        // Put all non-duplicate elements to the left of dupStart.
        if (nums[i] != nums[dupStart - 1]) {
            swap(nums[i], nums[dupStart++]);
        }
    }

    return dupStart;
}
