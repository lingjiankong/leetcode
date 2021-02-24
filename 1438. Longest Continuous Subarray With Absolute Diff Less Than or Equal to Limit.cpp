// ***
//
// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the
// absolute difference between any two elements of this subarray is less than or equal to limit.
//
//
// Example 1:
//
// Input: nums = [8,2,4,7], limit = 4
// Output: 2
//
// Explanation: All subarrays are:
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4.
// Therefore, the size of the longest subarray is 2.
//
//
// Example 2:
//
// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4
//
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
//
//
// Example 3:
//
// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3
//
//
// Constraints:
//
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^9
// 0 <= limit <= 10^9
//
// ***

// Use a sliding window of tree set
// X X X X X [l X X X X X X X r] X X X
// It might not be super intuitive so you need to memorize the solutions to these types of problems.
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;

        int left = 0;
        int longest = 0;
        for (int right = 0; right < nums.size(); ++right) {
            window.insert(nums[right]);
            while (*window.rbegin() - *window.begin() > limit) {
                window.erase(window.find(nums[left++]));
            }
            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};
