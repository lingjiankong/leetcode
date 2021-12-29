vector<int> find3Smallest(vector<int>& nums) {
    int firstMin = INT_MAX, secondMin = INT_MAX, thirdMin = INT_MAX;

    for (int i = 0; i < nums.size(); ++i) {
        /* Check if current element is less than
           firstMin, then update first, second and
           third */
        if (nums[i] < firstMin) {
            thirdMin = secondMin;
            secondMin = firstMin;
            firstMin = nums[i];
        }

        /* Check if current element is less than
        secondMin then update second and third */
        else if (nums[i] < secondMin) {
            thirdMin = secondMin;
            secondMin = nums[i];
        }

        /* Check if current element is less than
        then update third */
        else if (nums[i] < thirdMin)
            thirdMin = nums[i];
    }
}
