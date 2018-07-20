class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        if (nums.size() == 0)
            return 1;

        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]); // put nums[i] at the place it belongs to (nums[nums[i-1]])
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) // e.g. [1,99,3,4], 99 is not 2, then 2 is the first missing positive
                return i + 1;
        }
        return nums.size() + 1;
    }
};
