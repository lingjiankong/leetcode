class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if (nums.size() <= 1)
            return nums.size();

        int count = 1; // because nums is a sorted array, nums[0] just stays at where it is, therefore count starts at 1
        // count is the position of first occurance of a duplicate elment, i,e. nums[count] = counts[count-1]
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[count-1]) {
                swap(nums[count], nums[i]);
                ++count;
            }
        }
        return count;
    }
};
