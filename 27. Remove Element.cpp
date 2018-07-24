class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int count = 0; // count is the position of the first occurance of val, nums at [0, count) do not contain val
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                swap(nums[i], nums[count]);
                ++count;
            }
        }
        return count;
    }
};
