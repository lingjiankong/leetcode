// ***
//
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
// Example 1:
// Input: [3,4,5,1,2]
// Output: 1
//
// Example 2:
// Input: [4,5,6,7,0,1,2]
// Output: 0
//
// ***

// The smallest element is the rotation pivot.
// This question is the same as asking you where the rotation pivot is. This pivot is guaranteed to exist,
// that is why the condition in this question is while (left < right) instead of while (left <= right).
// Compare this question with the condition in 33. Search in Rotated Sotrted Array,
// in which element might not exist at all (therefore in that question the condition is while (left <= right))
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // In this case, the pivot is on the right half of the array
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            // In this case, the pivot is on the left half of the array.
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
        }

        return nums[right];
    }
};

// Devide and conquer
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        return findMin(nums, l, r);
    }

private:
    int findMin(vector<int>& nums, int l, int r) {
        // if the array is sorted, return the leftmost element.
        if (nums[l] <= nums[r]) {
            return nums[l];
        }

        // otherwise if the array is not sorted,
        // devide and conquer to find the min element of left and right subarray.
        int mid = l + (r - l) / 2;
        return min(findMin(nums, l, mid), findMin(nums, mid + 1, r));
    }
};
