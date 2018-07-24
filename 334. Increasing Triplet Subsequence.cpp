class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int min = INT_MAX; // most minimum element
        int secondMin = INT_MAX; // second most minimum element

        // <= (not <) is important, because we want increasing orders. If we want non-decreasing orders, we can do <
        for (int num : nums) {
            if (num <= min) {
                min = num;
            } else if (num <= secondMin) {
                secondMin = num;
            } else {
                return true;
            }
        }

        return false;
    }
};
