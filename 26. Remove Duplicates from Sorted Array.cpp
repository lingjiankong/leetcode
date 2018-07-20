class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() <= 1)
            return nums.size();

        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[count-1]) {
                std::swap(nums[count], nums[i]);
                ++count;
            }
        }
        return count;
    }
};
