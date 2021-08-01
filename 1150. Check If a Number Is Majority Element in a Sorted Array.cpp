// ***
//
// Given an array nums sorted in non-decreasing order, and a number target, return True if and only if target is a
// majority element. A majority element is an element that appears more than N/2 times in an array of length N.
//
// Example 1:
// Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
// Output: true
//
// Explanation:
// The value 5 appears 5 times and the length of the array is 9.
// Thus, 5 is a majority element because 5 > 9/2 is true.
//
// Example 2:
// Input: nums = [10,100,101,101], target = 101
// Output: false
//
// Explanation:
// The value 101 appears 2 times and the length of the array is 4.
// Thus, 101 is not a majority element because 2 > 4/2 is false.
//
//
// Constraints:
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 10^9
// 1 <= target <= 10^9
//
// ***
//
// If majority element exists, there are the following cases:
// [ x x x x x x x . . . . . . ] # majority at the beginning
// [ . . . x x x x x x x . . . ] # majority at the middle
// [ . . . . . . x x x x x x x ] # majority at the ending
//
// Using binary search, find the first and last occurrences of target. Then just calculate the difference between the
// indexes of these occurrences.

// Use built in function:
// std::upper_bound - returns an iterator pointing to the first element in the range [first, last) that is greater than
// value, or last if no such element is found.
// std::lower_bound - returns an iterator pointing to the first element in the range [first, last) that is not less than
// (i.e. greater or equal to) value, or last if no such element is found.
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        return upper_bound(begin(nums), end(nums), target) - lower_bound(begin(nums), end(nums), target) >
               nums.size() / 2;
    }
};

// Write binary search from scratch.
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        return upperBound(nums, target) - lowerBound(nums, target) > nums.size() / 2;
    }

private:
    int upperBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            }
        }

        return right;
    }

    int lowerBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid;
            }
        }

        return right;
    }
};
