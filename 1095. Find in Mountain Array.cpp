// ***
//
// (This problem is an interactive problem.)
//
// You may recall that an array mountainArr is a mountain array if and only if:
//
// mountainArr.length >= 3
// There exists some i with 0 < i < mountainArr.length - 1 such that:
// mountainArr[0] < mountainArr[1] < ... mountainArr[i-1] < mountainArr[i]
// mountainArr[i] > mountainArr[i+1] > ... > mountainArr[mountainArr.length - 1]
// Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target.  If such an
// index doesn't exist, return -1.
//
// You can't access the mountain array directly.  You may only access the array using a MountainArray interface:
//
// MountainArray.get(k) returns the element of the array at index k (0-indexed).
// MountainArray.length() returns the length of the array.
// Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer.  Also, any solutions that
// attempt to circumvent the judge will result in disqualification.
//
//
//
// Example 1:
//
// Input: array = [1,2,3,4,5,3,1], target = 3
// Output: 2
// Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
// Example 2:
//
// Input: array = [0,1,2,4,2,1], target = 3
// Output: -1
// Explanation: 3 does not exist in the array, so we return -1.
//
//
// Constraints:
//
// 3 <= mountain_arr.length() <= 10000
// 0 <= target <= 10^9
// 0 <= mountain_arr.get(index) <= 10^9
//
// ***

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int left, right, mid, peak = 0;

        // find index of peak
        left = 0;
        right = mountainArr.length() - 1;
        while (left < right) {
            mid = (left + right) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        peak = right;

        // find target in the left of peak
        left = 0;
        right = peak;
        while (left < right) {
            mid = (left + right) / 2;
            if (mountainArr.get(mid) < target) {
                left = mid + 1;
            } else if (mountainArr.get(mid) > target) {
                right = mid;
            } else {
                return mid;
            }
        }

        // find target in the right of peak
        left = peak;
        right = mountainArr.length();
        while (left < right) {
            mid = (left + right) / 2;
            if (mountainArr.get(mid) > target) {
                left = mid + 1;
            } else if (mountainArr.get(mid) < target) {
                right = mid;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
