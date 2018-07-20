class Solution {
public:
    // O(n)
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > unordered_set<int>(nums.cbegin(), nums.cend()).size();
    }
    // O(nlogn)
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
};
