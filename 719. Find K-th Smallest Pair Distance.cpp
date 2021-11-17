// ***
//
// The distance of a pair of integers a and b is defined as the absolute difference between a and b.
//
// Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and
// nums[j] where 0 <= i < j < nums.length.
//
//
// Example 1:
//
// Input: nums = [1,3,1], k = 1
// Output: 0
// Explanation: Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.
//
//
// Example 2:
//
// Input: nums = [1,1,1], k = 2
// Output: 0
//
//
// Example 3:
//
// Input: nums = [1,6,1], k = 3
// Output: 5
//
//
// Constraints:
//
// n == nums.length
// 2 <= n <= 10^4
// 0 <= nums[i] <= 10^6
// 1 <= k <= n * (n - 1) / 2
//
// ***

// Similar method as 378. Kth Smallest Element in a Sorted Matrix.
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.back() - nums[0] + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;

            int start = 0, count = 0;  // count: number of distance smaller than mid.
            for (int i = 0; i < nums.size(); ++i) {
                // if nums[i] - nums[start] > mid, it means the distance between nums[i] and nums[start] is too large,
                // so we need to ++start until nums[i] - nums[start] <= mid, in which case we have (i - start) pairs
                // which distances that are smaller than or equal to mid.
                //
                // You can also initialize start = 0 everytime inside the for loop. Correct but TLE.
                // note that start can only increase.
                while (start < nums.size() and nums[i] - nums[start] > mid) {
                    ++start;
                }
                count += i - start;
            }

            if (count == k) {
                right = mid;
            } else if (count < k) {
                left = mid + 1;
            } else if (count > k) {
                right = mid;
            }
        }

        return right;
    }
};
