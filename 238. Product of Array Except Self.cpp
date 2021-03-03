// ***
//
// Given an array nums of n integers where n > 1,
// return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
// Example:
//
// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Note: Please solve it without division and in O(n).
//
// ***
//
// In the first for loop, calculate the product of all numbers to the left of nums[i].
// Then in the second for loop, times the product of all numbers to the right of nums[i],
//
// Example:
// nums:                            [1,  2,  3,  4]
// Product to the left of nums[i]:  [1,  1,  2,  6]
// Product to the right of nums[i]: [24, 12, 4,  1]
// Multiplying to combine together: [24, 12, 8,  6]

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> forward(n, 1), backward(n, 1), toReturn(n);

    for (int i = 1; i < n; ++i) {
        forward[i] = forward[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; --i) {
        backward[i] = backward[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; ++i) {
        toReturn[i] = forward[i] * backward[i];
    }

    return toReturn;
}

// Same thing, no extra space.
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> toReturn(nums.size(), 1);

    int leftProduct = 1;
    for (int i = 0; i < nums.size(); ++i) {
        toReturn[i] = leftProduct;
        leftProduct *= nums[i];  // Update for next iteration
    }

    int rightProduct = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        toReturn[i] *= rightProduct;
        rightProduct *= nums[i];  // Update for next iteration
    }

    return toReturn;
}
