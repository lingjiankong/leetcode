// ***
//
// A peak element is an element that is greater than its neighbors.
//
// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
//
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
// You may imagine that nums[-1] = nums[n] = -∞.
//
// Example 1:
//
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:
//
// Input: nums = [1,2,1,3,5,6,4]
// Output: 1 or 5
// Explanation: Your function can return either index number 1 where the peak element is 2,
//              or index number 5 where the peak element is 6.
// Follow up: Your solution should be in logarithmic complexity.
//
// ***

// O(n)
// We are given that nums[-1] = nums[n] = -∞, so if we ever see a number which is less than previous number,
// previous number is a local maxima.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                return i - 1;
            }
        }
        return nums.size() - 1;
    }
};

// O(logn)
// Binary search.
// If nums[mid] < nums[mid + 1], then local maxima is to the right of mid, in this case left = mid + 1.
// Otherwise, either mid itself is the local maxima or local maxima is to the left of mid, in this case right = mid.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right;
    }
};
