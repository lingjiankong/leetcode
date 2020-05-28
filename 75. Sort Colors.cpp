// ***
//
// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are
// adjacent, with the colors in the order red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
// Note: You are not suppose to use the library's sort function for this problem.
//
// Example:
//
// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
//
// ***
//
// Maintain three pointers l, r, and i.
//
// l: Tracks the position which all elements to the left are 0
//
// i: Traverse in between l and r pointers
//
// r: Tracks the position which all elements to the right are 2
// (technically, all elements to the right of r + 1 are 2)
// (r itself might be still pointing to some non-2 element)
//
// Example:
//
// 0, 0, 0, 0, 1, 1, 1, 2, 1, 0, 2, 1, 0, 2, 2, 2, 2
//             l                       r
//                   i
//
// 0, 0, 0, 0, 1, 1, 1, 2, 1, 0, 2, 1, 0, 2, 2, 2, 2
//             l                       r
//                      i
//
// 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 2, 1, 2, 2, 2, 2, 2
//             l                    r
//                      i
//
// 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 2, 1, 2, 2, 2, 2, 2
//                l                 r
//                         i

void sortColors(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    int i = 0;

    // Why do we use while(i <= r) instead of using for(int i = 0; i <= nums.size(); ++i) ?
    // Because you see in the last else if loop (when nums[i]==2), i is not incremented.
    // See the example above. When nums[i] and nums[r] are swapped (second line to third line),
    // nums[i] becomes 0, and it is still NOT in the right position.
    // So there must be another swap between nums[l] and nums[i] (third line to fourth line).
    // After this swap, we may increment i. That's why we use a while loop instead of a for loop here,
    // because we would like to make sure that nums[i] is in the rigth position before increment i.
    while (i <= r) {
        if (nums[i] == 0) {
            swap(nums[l++], nums[i++]);
        } else if (nums[i] == 2) {
            swap(nums[i], nums[r--]);
        } else if (nums[i] == 1) {
            ++i;
        }
    }
}
