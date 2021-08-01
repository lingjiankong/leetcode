// ***
//
// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array
// such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
//
// Example 1:
// Input: nums = [1,2,3,1], k = 3
// Output: true
//
// Example 2:
// Input: nums = [1,0,1,1], k = 1
// Output: true
//
// Example 3:
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
//
// ***

// labuladong sliding window template
// window is of size up to k and contains all the unique elements you've seen
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> window;

    int left = 0, right = 0;
    while (right < nums.size()) {
        int num = nums[right++];

        // When we perform the check here, window.size() will never be > k.
        if (window.count(num)) {
            return true;
        }
        window.insert(num);

        while (right - left == k + 1) {
            int num = nums[left++];
            window.erase(num);
        }
    }

    return false;
}

// Sliding window using unordered_map.
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // key value pairs of num : index
    unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); ++i) {
        if (seen.count(nums[i])) {
            if (i - seen[nums[i]] <= k) {
                return true;
            }
        }
        seen[nums[i]] = i;
    }

    return false;
}
