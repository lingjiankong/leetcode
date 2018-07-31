class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> seen; // a sliding window of last k elements, use <long> to prevent overflow when nums[i]+t
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k)
                seen.erase(nums[i-k-1]);
            auto it = seen.lower_bound(static_cast<long>(nums[i]) - static_cast<long>(t)); // see if we can find a number >= nums[i]-t
            if (it != seen.end()) { // if we found a number >= nums[i]-t
                if (*it <= static_cast<long>(nums[i]) + static_cast<long>(t)) // then check if also that number <= nums[i]+t
                    return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};

// note:
// std::set::lower_bound - returns an iterator pointing to the first element in the range [first, last) that is greater or equal to value, or last if no such element is found.
// std::set::upper_bound - returns an iterator pointing to the first element in the range [first, last) that is greater than value, or last if no such element is found.
