// ***
//
// Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such
// that the value of the maximum array element in that subarray is in the range [left, right].
//
// The test cases are generated so that the answer will fit in a 32-bit integer.
//
//
//
// Example 1:
//
// Input: nums = [2,1,4,3], left = 2, right = 3
// Output: 3
// Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
//
//
// Example 2:
//
// Input: nums = [2,9,2,5,6], left = 2, right = 8
// Output: 7
//
// ***

// Brute force with optimization, TLE.
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > right) {
                continue;
            }

            int curMax = INT_MIN;
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] > right) {
                    break;
                }

                curMax = max(curMax, nums[j]);
                if (curMax >= left) {
                    ++res;
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }

private:
    // Calculate the number of subarray in nums such whose max elements are within [-∞, bound].
    //
    // 我们来看数组[2, 1, 4, 3]的最大值在[-∞, 4]范围内的子数组的个数。当遍历到2时，只有一个子数组[2]，
    // 遍历到1时，有三个子数组，[2], [1], [2,1]。当遍历到4时，有六个子数组，[2], [1], [4], [2,1], [1,4], [2,1,4]。
    // 当遍历到3时，有十个子数组。其实如果长度为n的数组的最大值在范围[-∞, x]内的话，其所有子数组都是符合题意的，
    // 而长度为n的数组共有n(n+1)/2个子数组，刚好是等差数列的求和公式。
    // 所以我们在遍历数组的时候，如果当前数组小于等于x，则cur自增1，然后将cur加到结果res中；
    // 如果大于x，则cur重置为0。这样我们可以正确求出最大值在[-∞, x]范围内的子数组的个数。
    int count(vector<int>& nums, int bound) {
        int res = 0, cur = 0;
        for (int x : nums) {
            cur = (x <= bound) ? cur + 1 : 0;
            res += cur;
        }
        return res;
    }
};
