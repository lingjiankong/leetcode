// ***
//
// Given an array of integers, find out whether there are two distinct indices i and j in the array such that
// the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at
// most k.
//
// Example 1:
//
// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true
//
// Example 2:
//
// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true
// Example 3:
//
// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false
//
// ***
//
// The idea is to store all numbers that satisfy the index requirement
// (the absolute difference between i and j is at most k) in a *tree* set, like a sliding window,
// then see among these numbers, if there is a number such that nums[i]-t <= nums[i] <= nums[i]+t.

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    // A sliding window of last k elements
    set<int> window;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > k) {
            window.erase(nums[i - k - 1]);
        }

        // See if we can find a number >= nums[i]-t in the window
        auto itr = window.lower_bound(nums[i] - t);

        // If we found a number >= nums[i]-t
        if (itr != window.end()) {
            // then check if also that number <= nums[i]+t
            if (*itr <= nums[i] + t) {
                return true;
            }
        }

        window.insert(nums[i]);
    }

    return false;
}

// To submit on leetcode, need to cast with <long>
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long> window;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > k) {
            window.erase(nums[i - k - 1]);
        }

        auto itr = window.lower_bound((long)(nums[i]) - (long)(t));
        if (itr != window.end()) {
            if (*itr <= (long)(nums[i]) + (long)(t)) {
                return true;
            }
        }

        window.insert(nums[i]);
    }

    return false;
}
