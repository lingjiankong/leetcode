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

// labuladong sliding window template
// (cast to long to submit on leetcode)
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> window;

    int left = 0, right = 0;
    while (right < nums.size()) {
        int num = nums[right++];
        auto itr = window.lower_bound(num - t);
        if ((itr != window.end()) and (*itr <= num + t)) {
            return true;
        }
        window.insert(num);

        while (window.size() == k + 1) {
            int num = nums[left++];
            window.erase(window.lower_bound(num));
        }
    }

    return false;
}
