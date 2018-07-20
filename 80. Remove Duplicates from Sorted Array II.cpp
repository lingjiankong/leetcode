class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() <= 2)
            return nums.size();

        int count = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[count-2]) {
                std::swap(nums[count], nums[i]);
                ++count;
            }
        }
        return count;
    }
};
