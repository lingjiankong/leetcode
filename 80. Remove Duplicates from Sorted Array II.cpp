// this problem uses the same method as 26. Remove Duplicates from Sorted Array. See that problem for intuition

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() <= 2)
            return nums.size();

        int count = 2;
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] != nums[count-2]) {
                swap(nums[count], nums[i]);
                ++count;
            }
        }
        return count;
    }
};
