// ***
//
// Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array
// that can make triangles if we take them as side lengths of a triangle.
//
// Example 1:
// Input: [2,2,3,4]
// Output: 3
//
// Explanation:
// Valid combinations are:
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
//
// Note:
// The length of the given array won't exceed 1000.
// The integers in the given array are in the range of [0, 1000].
//
// ***

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int numTriangles = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                // As long as target is less than nums[i] + nums[j] (target needs to be non zeros, of course),
                // we can form a valid triangle.
                // Using binary search to find how many targets are less than nums[i] + nums[j]
                int target = nums[i] + nums[j];

                int left = j + 1, right = nums.size();
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

                // right is the first index in nums which is greater or equal to target
                // Therefore, right - 1 is the last index in nums which is smaller than target.
                // Hence, right - 1 - j is the count of such numbers.
                numTriangles += (right - 1) - j;
            }
        }

        return numTriangles;
    }
};

