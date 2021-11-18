// ***
//
// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the
// duplicate one.
//
// Example 1:
// Input: [1,3,4,2,2]
// Output: 2
//
// Example 2:
// Input: [3,1,3,4,2]
// Output: 3
//
// Note:
// - You must not modify the array (assume the array is read only).
// - You must use only constant, O(1) extra space.
// - Your runtime complexity should be less than O(n2).
// - There is only one duplicate number in the array, but it could be repeated more than once.
//
// ***
//
// You cannot modify the array and you cannot copy the array to sort it (which will result in O(n) space, not allowed in
// this question). Binary search is a O(nlogn), there's another O(n) method that uses the idea in linked list cycle. You
// can do that if you have time in the future.
//
// Nums is unsorted, but we show sorted nums for clarity. Our algorithm works with unsorted nums.
// Note that we are guaranteed that there is only *one* duplicate number in the array, but it could be repeated more
// than once. So something like [1, 2, 3, 3, 3, 4, 4, 4] is not possible.
//
// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive)
// In our case, there are a total of 11 elements, each element is between 1 and 10 inclusive.
//
// first mid = 5
// no duplicate in [1, 5]
// nums  [1 3 5 6 8 8 8 8 8 9 10]
// index [0 1 2 3 4 5 6 7 8 9 10]
//
// first mid = 5
// duplicate in [1, 5]
// nums  [3 3 3 3 3 4 6 7 9 10]
// index [0 1 2 3 4 5 6 7 8 9 10]
//
// Every time you calculate a new mid, you iterate through all nums and find
// how many elements are less than or equal to mid, and store it in count.
// Either the first half or the second half of the range is "too crowded" (i.e. with duplicate element).

int findDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        int count = 0;
        for (int num : nums) {
            if (num <= mid) {
                ++count;
            }
        }

        // Right half too crowded.
        if (count <= mid) {
            left = mid + 1;
        }
        // Left half too crowded.
        else {
            right = mid;
        }
    }

    return right;
}
