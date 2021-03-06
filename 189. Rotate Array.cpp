// ***
//
// Given an array, rotate the array to the right by k steps, where k is non-negative.
//
// Example 1:
// Input: [1,2,3,4,5,6,7] and k = 3
// Output: [5,6,7,1,2,3,4]
//
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
//
// Example 2:
// Input: [-1,-100,3,99] and k = 2
// Output: [3,99,-1,-100]
//
// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// Given: [1 2 3 4 5 6 7], k = 3
//
// ***
//
// Example: if k = 3,
// reverse(nums.begin(), nums.end());       -> [7 6 5 4 3 2 1]
// reverse(nums.begin(), nums.begin() + k); -> [5 6 7 4 3 2 1]
// reverse(nums.begin() + k, nums.end());   -> [5 6 7 1 2 3 4]

void rotate(vector<int>& nums, int k) {
    k %= nums.size();

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
