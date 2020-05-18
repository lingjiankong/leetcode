// ***
//
// Given an array nums, write a function to move all 0's to the end of it while
// maintaining the relative order of the non-zero elements.
//
// Example:
// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
//
// Note:
// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.
//
// ***
//
// The thinking process is the same as 27. Remove Element.
//
// The idea is to put all non-zero elements to the left of zeroStart.
// Everything to the left of zeroStart is guaranteed to be non-zero.
//
// [3 4 1 5 0 0 2 4 5]
// 			^   ^
//          |   i
// 			zeroStart
//
// [3 4 1 5 2 0 0 4 5]
// 			  ^ ^
//            | i
// 			  zeroStart
//
// [3 4 1 5 2 0 0 4 5]
// 			  ^   ^
//            |   i
// 			  zeroStart
//
// [3 4 1 5 2 4 0 0 5]
// 			    ^ ^
//              | i
// 			    zeroStart
//
void moveZeroes(vector<int>& nums) {
    int zeroStart = 0;

    for (int i = 0; i < nums.size(); ++i) {
        // Put all non-zero elements to the left of zeroStart.
        if (nums[i] != 0) {
            swap(nums[i], nums[zeroStart++]);
        }
    }
}
